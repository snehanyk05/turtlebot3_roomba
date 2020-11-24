/**
 *  MIT License
 *
 *  Copyright (c) 2020 Sneha Nayak
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without
 *  limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, and/or sell copies of the Software, and to permit persons to
 *  whom the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */
/**
 * Copyright 2020
 * Copyright owner: Sneha Nayak
 * [legal/copyright]
 */
#include "Walker.h"
/**
 * @brief callback for reading laser data
 * @param sensor_msgs::LaserScan
 * @return None 
 */
void WalkingBot::lasercallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    double minDistance = 0.3;
    for (int i = 0; i < 70; i++) {
        if (msg->ranges[i] < minDistance) {
            minDistance = msg->ranges[i];
        }
    }
    for (int i = 290; i < 360; i++) {
        if (msg->ranges[i] < minDistance) {
            minDistance = msg->ranges[i];
        }
    }
    distance = minDistance;
}
/**
 * @brief class Contructor
 * @param Node handle node
 * @return None 
 */
WalkingBot::WalkingBot(ros::NodeHandle node) {
    // LaserScan Subscriber for reading laser data
    ros::Subscriber laserSubscriber =
node.subscribe("/scan", 1000, &WalkingBot::lasercallback, this);

    // Publisher to publish commad velocities to turtlebot
    ros::Publisher velocityPublisher =
node.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
    while (ros::ok()) {
        // Declare and initialize twist
        geometry_msgs::Twist twist;
        twist.linear.x = 0.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = 0.0;

        if (distance >= 0.3) {
            ROS_INFO_STREAM("Moving Forward!" << distance);
            twist.linear.x = 0.1;
        } else {
            ROS_INFO_STREAM("Rotating!" << distance);
            twist.angular.z = 0.2;
        }
        velocityPublisher.publish(twist);
        ros::spinOnce();
    }
}
