#include "ros/ros.h"
#include "ros_code/ros_msg.h"
#include <iostream>
#include <sstream>


void number_callback(const ros_code::ros_msg::ConstPtr& msg) {
	ROS_INFO("Recieved  greeting [%s]",msg->greeting.c_str());
	ROS_INFO("Recieved  [%d]",msg->number);
}

int main(int argc, char **argv) {

	//Initializing ROS node with a name of demo_topic_subscriber
	ros::init(argc, argv,"my_msg_subscriber");
	//Created a nodehandle object
	ros::NodeHandle node_obj;
	//Create a publisher object
	ros::Subscriber number_subscriber = node_obj.subscribe("/ros_msg_topic",10,number_callback);
	//Spinning the node
	ros::spin();
	return 0;
}
