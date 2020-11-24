Modify the TurtleBot simulation from the lecture and implement a simple walker algorithm much like a Roomba robot vacuum cleaner. The robot should move forward until it reaches an obstacle (but not colliding), then rotate in place until the way ahead is clear, then move forward again and repeat. Select/Modify a Gazebo World that can quickly and frequently test this behavior (add sufficient obstacles and enclose with walls such that robot cannot escape into open, endless space).

## License
```
MIT License

Copyright (c) 2020 Sneha Nayak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
## Dependencies

The following dependencies are required to run this package:

1. ROS Melodic
2. catkin (http://wiki.ros.org/catkin#Installing_catkin)
3. Ubuntu 18.04 For installing ROS (http://wiki.ros.org/melodic/Installation)
4. C++ 11
5. catkin

## Standard install via command-line
```
cd <<Your_catkin_workspace>>/src
mkdir beginner_tutorials
cd beginner_tutorials
git clone --recursive https://github.com/snehanyk05/beginner_tutorials
cd ../..
catkin_make

```

Open the following terminals and run the following commands in them:

1. Terminal 1:
```
roscore
```

2. Terminal 2:
Passing record=true for recording of bag file:
```
cd <<Your_catkin_workspace>>/src
source devel/setup.bash
roslaunch turtlebot3_roomba turtlebot3_roomba.launch record:=true
```

Passing record=false for not recording the bag file:
```
cd <<Your_catkin_workspace>>/src
source devel/setup.bash
roslaunch turtlebot3_roomba turtlebot3_roomba.launch record:=false
```


## Print information in a bag file
1. Terminal 1:
```
cd <<Your_catkin_workspace>>/src
source devel/setup.bash
cd src/turtlebot3_roomba/results/
rosbag info turtlebot3_roomba.bag
```

## Playing a rosbag file
1. Terminal 1 (run master node):
```
roscore
```

2. Terminal 2 (play rosbag):
```
cd <<Your_catkin_workspace>>/src
source devel/setup.bash
rosbag play src/turtlebot3_roomba/results/turtlebot3_roomba.bag
```