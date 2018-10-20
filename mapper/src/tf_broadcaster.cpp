#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "tf_broadcaster");
    ros::NodeHandle node;

    tf::TransformBroadcaster broadcaster;
    tf::Transform laser_to_odom;
    tf::Transform odom_to_map;
    tf::TransformListener listener;
    ros::Rate rate(30.0);
    while (node.ok()){
        tf::StampedTransform transform;
        try{
            listener.lookupTransform("odom", "base_link", ros::Time(0), transform);
        }
        catch (tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
        }
        laser_to_odom.setOrigin(transform.getOrigin());
        laser_to_odom.setRotation(transform.getRotation());
        broadcaster.sendTransform(tf::StampedTransform(laser_to_odom, ros::Time::now(), "odom", "laser"));
	odom_to_map.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
        tf::Quaternion q;
        q.setRPY(0, 0, 0);
        odom_to_map.setRotation(q);
        broadcaster.sendTransform(tf::StampedTransform(odom_to_map, ros::Time::now(), "map", "odom"));
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
};
