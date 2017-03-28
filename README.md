# Optic Disc Detector
[![Build Status](https://travis-ci.org/Ravirael/opto-disc-detector.svg?branch=master)](https://travis-ci.org/Ravirael/opto-disc-detector)
## Description
Batch program to detect
[optic disc](https://en.wikipedia.org/wiki/Optic_disc) on retinography
photograph.

Do **not** confuse with *optical disc*!

## Usage
```bash
optic-disc-detector -i /path/to/input.jpg
optic-disc-detector --input /path/to/input.jpg
optic-disc-detector --input=/path/to/input.jpg
optic-disc-detector -i /path/to/input.jpg -o /path/to/output.jpg
optic-disc-detector --input=/path/to/input.jpg --output=/path/to/output.jpg
```
## Parameters

### Mandatory
* **-i** *<input_file_path>* - path to input image (jpg, png, bmp)

### Optional
* **-o** *output_file_path* - path to output image (jpg, png, bmp)
* **--minRadius** *<double_value>* - minimum radius, % of image width (0 - 1)
* **--maxRadius** *<double_value>* - maximum radius, % of image width (0 - 1)
* **--minDistance** *<double_value>* - minimum distance between centers, % of image width (0 - 1)
* **--cannyThreshold** *<integer_value>* - upper threshold of Canny filter (0 - 255)
* **--accumulatorThreshold** *<integer_value>* - accumulator detection threshold ( > 0)

### Optional group
* **--x** *<integer_value>* - *x* of correct circle center (0 - width)
* **--y** *<integer_value>* - *y* of correct circle center (0 - height)
* **--radius** *<integer_value>* - radius of correct circle (0 - width)


## Output
Circle is output in JSON format

### Example
```json
{
   "circle":{
      "center":{
         "x":868,
         "y":1171
      },
      "radius":169
   },
   "statistics":{
      "positive":100,
      "negative":1231,
      "truePositive":60,
      "trueNegative":1200,
      "falsePositive":40,
      "falseNegative":31,
      "sensitivity":0.6,
      "specificity":0.9
   }
}
```