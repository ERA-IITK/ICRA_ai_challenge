#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "lidartop_broadcaster");
    ros::NodeHandle node;

    tf::TransformBroadcaster broadcaster;
    tf::Transform lidartop;

    ros::Rate rate(30.0);
    while (node.ok()){
        lidartop.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
        lidartop.setRotation(tf::Quaternion(1, 0, 0, 0));
        broadcaster.sendTransform(tf::StampedTransform(lidartop, ros::Time::now(), "/map", "lidartop"));
        rate.sleep();
    }
    return 0;
};
