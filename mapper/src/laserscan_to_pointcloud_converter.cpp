#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>

ros::Publisher pointcloud_pub;
laser_geometry::LaserProjection projector_;
tf::TransformListener listener_;

void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in) {
    if(!listener_.waitForTransform(scan_in->header.frame_id, "/base_link", scan_in->header.stamp + ros::Duration().fromSec(scan_in->ranges.size()*scan_in->time_increment), ros::Duration(1.0))){
        return;
    }

    sensor_msgs::PointCloud2 cloud;
    projector_.transformLaserScanToPointCloud("/base_link", *scan_in, cloud, listener_);
    pointcloud_pub.publish(cloud);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "laserscan_to_pointcloud_converter");
    ros::NodeHandle nh;
    pointcloud_pub = nh.advertise<sensor_msgs::PointCloud2>("cloud_in", 1000);
    ros::Subscriber laserscan_sub = nh.subscribe("scan", 1000, scanCallback);
    ros::spin();
    return 0;
};
