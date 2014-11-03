#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include "drone_control_ps3.hpp"


DroneControlPs3::DroneControlPs3():
	x_linear_(13),
	x_angular_(2),
	y_linear_(12),
	y_angular_(3),
	z_linear_(1),
	z_angular_(0),
	x_l_scale_(1.0), 
	x_a_scale_(1.0),
	y_l_scale_(1.0), 
	y_a_scale_(1.0),
	z_l_scale_(1.0), 
	z_a_scale_(1.0)
{

	nh_.param("x_linear", x_linear_, x_linear_);
	nh_.param("x_angular", x_angular_, x_angular_);
	nh_.param("y_linear", y_linear_, y_linear_);
	nh_.param("y_angular", y_angular_, y_angular_);
	nh_.param("z_linear", z_linear_, z_linear_);
	nh_.param("z_angular", z_angular_, z_angular_);
	nh_.param("scale_a", x_a_scale_, x_a_scale_);
	nh_.param("scale_l", x_l_scale_, x_l_scale_);
	nh_.param("scale_a", y_a_scale_, y_a_scale_);
	nh_.param("scale_l", y_l_scale_, y_l_scale_);
	nh_.param("scale_a", z_a_scale_, z_a_scale_);
	nh_.param("scale_l", z_l_scale_, z_l_scale_);
	nh_.param("x_scale_a", x_a_scale_, x_a_scale_);
	nh_.param("x_scale_l", x_l_scale_, x_l_scale_);
	nh_.param("y_scale_a", y_a_scale_, y_a_scale_);
	nh_.param("y_scale_l", y_l_scale_, y_l_scale_);
	nh_.param("z_scale_a", z_a_scale_, z_a_scale_);
	nh_.param("z_scale_l", z_l_scale_, z_l_scale_);

	vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel",1000);

	joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &DroneControlPs3::joyCallback, this);

}

void DroneControlPs3::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	geometry_msgs::Twist vel;
	
	vel.angular.x = x_a_scale_*joy->axes[x_angular_];
	vel.angular.y = y_a_scale_*joy->axes[y_angular_];
	vel.angular.z = z_a_scale_*joy->axes[z_angular_];
	vel.linear.x = x_l_scale_*joy->axes[x_linear_];
	vel.linear.y = y_l_scale_*joy->axes[y_linear_];
	vel.linear.z = z_l_scale_*joy->axes[z_linear_];
	vel_pub_.publish(vel);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "drone_control");
	ROS_DEBUG("help!");
	DroneControlPs3 drone_control;

	ros::spin();
}
