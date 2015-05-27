#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream>
#include "Controllers/sb_ai.h"
#include <geometry_msgs/Twist.h>

#include "Controllers/ControllerBase.hpp"
#include "Controllers/DijkstraController.hpp"
#include "Controllers/VisionController.hpp"
#include "Controllers/LidarController.hpp"
//#include "Controllers/DSLiteController.hpp"

ai::ControllerBase* GetController(ros::NodeHandle& nh)
{
	ros::NodeHandle private_nh("~");
	std::string param;
	private_nh.getParam(MODE_PARAM, param);
	
	if (param == "dijkstra")
	{
	  std::cout << "Running Dijkstra!" << std::endl;
		return new ai::DijkstraController(nh);
	}else if(param=="vision"){
	  std::cout << "Running Vision!" << std::endl;
		return new ai::VisionController();
	}else if(param=="lidar"){
	  std::cout << "Running Lidar!" << std::endl;
		return new ai::LidarController(nh);
	//}else if(param=="dslite"){ // this one is pretty broken - its implementation is basically a copy-paste of DijkstraController's...
	//	return new ai::DSLiteController(nh);
	}else{
		std::cout << "Invalid " << MODE_PARAM << " '" << param << "'." << std::endl;
	}
	
	std::cout << "Current options: " << std::endl;
	std::cout << "\tdijkstra" << std::endl;
	std::cout << "\tlidar" << std::endl;
	std::cout << "\tvision" << std::endl;
	std::cout << "Defaulting to dijkstra" << std::endl;
	return new ai::DijkstraController(nh);
}

// main function that runs this node
int main(int argc, char **argv)
{

	// Initializes this node. 
	// First 2 arguments are for ROS arguments and name remapping.
	// Last argument is for the name of this node.
	ros::init(argc, argv, AI_NODE_NAME);
	
	// Main access point to communication with ROS system.
	ros::NodeHandle nh;
	
	// Initialize publisher to PUB_TOPIC.
	// Second argument for advertise is the buffer size.
	ros::Publisher car_pub = nh.advertise<geometry_msgs::Twist>(PUB_TOPIC, 10);	
	
	ai::ControllerBase* controller = GetController(nh);
	if(!controller) return EXIT_FAILURE;
	
	// Frequency of the loop. 
	// eg. 10 = 10hz
	ros::Rate loop_rate(controller->GetClockSpeed());

	while (ros::ok()) {

		car_pub.publish(controller->Update());	// this is where we publish twist output
		
		ros::spinOnce();	// required for subscriptions
		
		loop_rate.sleep();	// sleep for the time remaining to hit frequency loop rate
	
	}

	return 0;
}
