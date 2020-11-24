#ifndef TURTLEBOT_WALKER_ALGORITHM_INCLUDE_WALKER_H_
#define TURTLEBOT_WALKER_ALGORITHM_INCLUDE_WALKER_H_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>

class Walker {
 public:
     /**
       * @brief      Constructs the Walker object.
       * @param      node  ros::NodeHandle.
     */
     explicit Walker(ros::NodeHandle node);

     /**
      * @brief      Callback for subscriber.
      * @param      data  sensor_msgs::LaserScan::ConstPtr.
     */
     void callback(const sensor_msgs::LaserScan::ConstPtr& data);
    //  std::vector<float> splitVector(std::vector<float>, int start, int end);
    //  float minDistance(std::vector<float> vector);
    //  void take_action(std::map<std::string, float> regions);
 private:
     // Variable to store distance.
     double distance;
     double linear_x,angular_z;
};
#endif