cmake_minimum_required(VERSION 2.8.3)
project(mapper)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  laser_geometry
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(tf_broadcaster src/tf_broadcaster.cpp)
target_link_libraries(tf_broadcaster ${catkin_LIBRARIES})

add_executable(laserscan_to_pointcloud_converter src/laserscan_to_pointcloud_converter.cpp)
target_link_libraries(laserscan_to_pointcloud_converter ${catkin_LIBRARIES})
