# Sahara - Software Build Examples

This repository contains sample (and simple) software repositories that are used to motivate different software build cases for the Sahara platform. See below for specifics.

## Arduino Builds

The following samples are specific to builds targeting Arduino devices.

### multi_c_sample

In this sample, we have an Arduino program that uses both a standard Arduino library (Mouse - part of USBHost) and a custom c/c++ library (packet). This is a complex build scenario in which the remote server must handle multiple, distinct sources.

To build this project via Sahara, modify the file code.yaml in your project as follows:
```

```

## Authors

* **Josh Kimmel**