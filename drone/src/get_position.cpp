#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
void callbackSomething(const geometry_msgs::PoseStamped& msg) {
	std::cout << msg.pose.position.x << ","
				<< msg.pose.position.y << ","
				<< msg.pose.position.z << "," << std::endl; 


	 

}

int main (int argc, char* argv[]) {
	ros::init(argc, argv, "drone_control");
	ros::NodeHandle nh; 
	ros::Subscriber joy_sub_ = nh.subscribe("ground_truth_to_tf/pose", 10, callbackSomething);
	ros::spin();
}