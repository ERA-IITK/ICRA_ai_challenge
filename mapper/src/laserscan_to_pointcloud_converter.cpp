#include <ros/ros.h>
#include <laser_geometry/laser_geometry.h>

ros::Publisher pointcloud_pub;

void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in) {
    laser_geometry::LaserProjection projector_;
    sensor_msgs::PointCloud2 cloud;
    projector_.projectLaser(*scan_in, cloud);
    pointcloud_pub.publish(cloud);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "laserscan_to_pointcloud_converter");
    ros::NodeHandle nh;
    pointcloud_pub = nh.advertise<sensor_msgs::PointCloud2>("/cloud_in", 1000);
    ros::NodeHandle nh_prv("~");
    std::string laserscan_topic = "/scan";
    nh_prv.getParam("laserscan", laserscan_topic);
    ros::Subscriber laserscan_sub = nh.subscribe(laserscan_topic, 1000, scanCallback);
    ros::spin();
    return 0;
};
