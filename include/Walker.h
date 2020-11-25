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
#ifndef TURTLEBOT_WALKER_ALGORITHM_INCLUDE_WALKER_H_
#define TURTLEBOT_WALKER_ALGORITHM_INCLUDE_WALKER_H_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include "geometry_msgs/Twist.h"

class WalkingBot {
 public:
     /**
       * @brief      Constructs the WalkingBot object.
       * @param      node  ros::NodeHandle.
     */
     explicit WalkingBot(ros::NodeHandle node);

     /**
      * @brief      Callback for subscriber.
      * @param      msg  sensor_msgs::LaserScan::ConstPtr.
     */
     void lasercallback(const sensor_msgs::LaserScan::ConstPtr& msg);
     ~WalkingBot() {}
 private:
     // Variable to store distance.
     double distance;
};
#endif