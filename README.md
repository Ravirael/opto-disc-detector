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

## Output
Circle is output in JSON format

### Example
```json
{"center":{"x":868,"y":1171},"radius":169}
```