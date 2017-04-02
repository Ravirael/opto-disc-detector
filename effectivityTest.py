#!/bin/python
from subprocess import Popen, PIPE
from glob import glob
import sys
import json

class Circle:
    def __init__(self, x, y, radius):
        self.x = x
        self.y = y
        self.radius = radius

    def __abs__(self):
        return Circle(abs(self.x), abs(self.y), abs(self.radius))

    def __sub__(self, circle):
        return Circle(self.x - circle.x, self.y - circle.y, self.radius - circle.radius)

    def isSimilar(self, circle, centerMargin, radiusMargin):
        circleDifference = abs(self - circle)
        return circleDifference.x < centerMargin and circleDifference.y < centerMargin and circleDifference.radius < radiusMargin

    def __str__(self):
        return "x:{}, y:{}, radius:{}".format(self.x, self.y, self.radius)

if len(sys.argv) < 3:
    print("Usage:")
    print("{} <test_images_directory> <optic_disc_centers_json> <optic_disc_detector_path> <optic_disc_detector_arguments>\n".format(sys.argv[0]))
    print("Don't pass -i or --input argument. It will be added automagically.")
else:
    testImagesDirectory = sys.argv[1]

    with open(sys.argv[2]) as json_data:
        testData = json.load(json_data)
        correctDetections = 0

        for row in testData:
            expectedCircle = Circle(row['x'], row['y'], row['radius'])
            print('Image: {}'.format(row['image']))
            print('Expected:\t{}'.format(expectedCircle))
            process = Popen(sys.argv[3:] + ["-i", testImagesDirectory + "/" + row['image'] + ".jpg",
                                            "-o", "TestResults/" + row['image'] + ".jpg",
                                            "--x",str(expectedCircle.x),
                                            "--y",str(expectedCircle.y),
                                            "--radius",str(expectedCircle.radius)], stdout=PIPE)
            (output, err) = process.communicate()
            process.wait()
            stats = json.loads(output)['statistics']
            circ = json.loads(output)['circle']
            detectedCircle = Circle(circ['center']['x'], circ['center']['y'], circ['radius'])
            print('Result:  \t{}'.format(detectedCircle))
            print('Diff:    \t{}'.format(detectedCircle - expectedCircle))
            print('Sensitivity: {}\nSpecificity: {}'.format(stats['sensitivity'], stats['specificity']))
            print('Accuracy: {}'.format(stats['accuracy']))
            if stats['sensitivity'] >= 0.75 and stats['specificity'] >= 0.75:#detectedCircle.isSimilar(expectedCircle, 100, 50):
                print('Correct!')
                correctDetections += 1
            else:
                print('Incorrect!')
            print('')

        print("Correct detections: {}\nTest cases: {}\nPercentage: {}%".format(correctDetections, len(testData), 100*correctDetections//len(testData)))








