#!/bin/python
from subprocess import call
from glob import glob
import sys

if len(sys.argv) < 3:
    print("Usage:")
    print("{} <test_images_directory> <optic_disc_detector_path> <optic_disc_detector_arguments>\n".format(sys.argv[0]))
    print("Don't pass -i or --input argument. It will be added automagically.")
else:
    imageFileExtensions = ["*.png", "*.jpg", "*.jpeg", "*.JPG", "*.JPEG", "*.bmp"]
    testFilesListOfLists = [glob(sys.argv[1] + "/" + extension) for extension in imageFileExtensions]
    testFiles = [item for sublist in testFilesListOfLists for item in sublist]

    print(testFiles)

    for file in testFiles:
        call(sys.argv[2:] + ["-i", file])


