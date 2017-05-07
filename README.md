# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


## Reflection
In this project I implemented a PID controller for both the throttle and the steering of the car. The implementation of the pid controller equation can be found on the PID.cpp under the method CalculateControl.
A pid controller is provides control based on feedback from a system, it takes the error value ( difference between the desired values of a system and the actual measured system ) and adjusts a control like steering / throttle to reduce this error.

In case of the steering angle the error term is the cross track error (CTE) which tells us how much a vehicle has deviated from a straight line between two waypoints of the planned route. This can be used to correct the steering of the vehicle to make sure it follows the planned route. 

The three components of the equation have different effects on the control:
1. The P constant determines the correction in proportion to the error. if the error is large and positive, the error is large and positive. The P component is the main variable which brings the car to a correct state.
2. The D constant determines the correction based on the rate of change of the error. This helps the controller converge to a stable state faster and smoother than the P control alone.
3. The I constant determines the control component based on the Integral of the error. This helps correct for any bias such as a vehicle being built slightly disproportionally/easily turning left but not right. In an ideal system the I constant may not do much but in real life scenarios, without the correction of the I control we would find the car to always converge to a constant error term which isnt 0.

To determine the P,D and I constants for the vehicle in the simulation, i set all the constants to 0 and manually tweeked each variable in the order P,D and I to determine suitable values. The constants I used were P= 0.15, I=0.0004, D=6.0

To determine the PID controller for the Throttle I decided to design a new error term which i call the speed error.
I define this error as  speed_error = (speed - 400)/ (20 + cte + angle)
The error term for speed control was designed to make the car slow down when it is trying to take a very large turn or when the cross tracking error is very high but try to make sure that the car tries to accelerate to maximum speed. The maximum speed is acheived by the numerator term (speed - 400) and the control for slowing down is found in the denominator term ( 20 + cte + angle). The constants 400 was chosen to ensure high acceleration and the constant 20 was chosen in this case to ensure that the error term is not getting a divide by 0 error.

The same method of manually tweaking the constants were used to determine the throttle control. The constants I used were P=0.15, I=0, D=0.4

A video of the car driving with the designed controller can be found on this [video](https://youtu.be/p_8nCkNSr68)