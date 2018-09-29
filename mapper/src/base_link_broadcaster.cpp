#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "base_link_broadcaster");
    ros::NodeHandle node;

    tf::TransformBroadcaster broadcaster;
    tf::Transform reference_frame;

    ros::Rate rate(30.0);
    while (node.ok()){
        reference_frame.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
        reference_frame.setRotation(tf::Quaternion(1, 0, 0, 0));
        broadcaster.sendTransform(tf::StampedTransform(reference_frame, ros::Time::now(), "/world", "base_link"));
        rate.sleep();
    }
    return 0;
};
