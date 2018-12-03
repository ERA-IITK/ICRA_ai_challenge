# hardware

## Overview

This is the ROS package that will start all the hardware connected to the main robot.

The `mapper` package has been tested under [ROS](http://www.ros.org) Kinetic and Ubuntu 16.04 LTS.

## Setting up hardware

### Dependencies

- [std_msgs](http://wiki.ros.org/std_msgs)

### Building

Run the following command:

```
cd ~/catkin_ws
catkin_make --pkg hardware
```

## Usage

To run the the Hokuyo URG LiDAR:
```
roslaunch mapper hokuyo.launch
```

To run the the Slamtec RPLIDAR:
```
roslaunch mapper rplidar.launch
```

## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/ERA-IITK/ICRA_ai_challenge/issues).
