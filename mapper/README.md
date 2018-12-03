# mapper

## Overview

This is the ROS package that will process point cloud data and make a map out of it. If the raw data is of type [sensor_msgs/LaserScan], there is a converter which will convert it to [sensor_msgs/PointCloud2] else the processed point cloud (of type [sensor_msgs/PointCloud2]) has to be provided.

The `mapper` package has been tested under [ROS](http://www.ros.org) Kinetic and Ubuntu 16.04 LTS.

The ideal hardware used is a [Slamtec RPLIDAR A1](https://www.logitech.com/en-in/product/c930e-webcam)

## Setting up mapper

### Dependencies

- [sensor_msgs](http://wiki.ros.org/sensor_msgs)
- [std_msgs](http://wiki.ros.org/std_msgs)
- [laser_geometry](http://wiki.ros.org/laser_geometry)
- [tf](http://wiki.ros.org/tf)

### Building

Install [`octomap`](https://github.com/OctoMap/octomap).

Install the ros plugin:
```
sudo apt-get install ros-kinetic-octomap
```
Run the following command:
```
cd ~/catkin_ws
catkin_make --pkg mapper
```

## Usage

If the raw data is of type [sensor_msgs/LaserScan], run:
```
rosrun mapper laserscan_to_pointcloud_converter
```

To run the mapper:
```
roslaunch mapper octomap_server_launch.launch
```

To visualize the map, run `rviz` and add `OccupancyMap` from the `octomap_rviz_plugins`.

## Nodes

### laserscan_to_pointcloud_converter

This node takes in data of type [sensor_msgs/LaserScan] and published data of type [sensor_msgs/PointCloud2].

#### Subscribed Topics
* **`/p3dx/laser/scan`** ([sensor_msgs/LaserScan])

#### Published Topics
* **`/cloud_in`** ([sensor_msgs/PointCloud2])

### tf_broadcaster

This node publishes the transforms between `odom` and `map` and between `laser` and `odom`.

## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/ERA-IITK/ICRA_ai_challenge/issues).

[sensor_msgs/LaserScan]: http://docs.ros.org/kinetic/api/sensor_msgs/html/msg/LaserScan.html
[sensor_msgs/PointCloud2]: http://docs.ros.org/kinetic/api/sensor_msgs/html/msg/PointCloud2.html