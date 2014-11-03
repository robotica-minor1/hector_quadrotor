#ifndef DRONE_CONTROL_PS3_HPP_
#define DRONE_CONTROL_PS3_HPP_
#include <ros/ros.h>


class DroneControlPs3
{
public:
	DroneControlPs3();

private:
	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
	
	ros::NodeHandle nh_;

	int x_linear_, x_angular_,y_linear_, y_angular_,z_linear_, z_angular_;
	double x_l_scale_, x_a_scale_,y_l_scale_, y_a_scale_,z_l_scale_, z_a_scale_;
	ros::Publisher vel_pub_,fb_pub_;
	ros::Subscriber joy_sub_;
};
#endif //DRONE_CONTROL_PS3_HPP_
