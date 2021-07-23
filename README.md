# Sahara - Software Build Examples

This repository contains sample (and simple) software repositories that are used to motivate different software build cases for the Sahara platform. See below for specifics.

## Arduino Builds

The following samples are specific to builds targeting Arduino devices.

### multi_c_sample

In this sample, we have an Arduino program that uses both a standard Arduino library (Mouse - part of USBHost) and a custom c/c++ library (packet). This is a complex build scenario in which the remote server must handle multiple, distinct sources.

To build this project via Sahara, modify the file code.yaml in your project as follows:
```
buildPath: multi_c_sample
target:
    platform: arduino
    specs:
        name: multi_c_sample
        boardTag: micro
systemLibs:
    - Mouse
userLibs:
    - packet
projId: [id_of_project]
        
```

### Arduino Basic Examples

The following subfolders correspond exactly to basic examples listed on the official Arduino website:
* [AnalogReadSerial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial)
* [DigitalReadSerial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial)
* [Fade](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade)
* [ReadAnalogVoltage](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage)
* [SimpleBlink](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink)

To build these projects via Sahara, modify the file code.yaml in your project as follows:
```
buildPath: [name_of_example]
target:
    platform: arduino
    specs:
        name: [name_of_example]
        boardTag: micro
systemLibs: []
userLibs: []
projId: [id_of_project]
        
```

## Authors

* **Josh Kimmel**