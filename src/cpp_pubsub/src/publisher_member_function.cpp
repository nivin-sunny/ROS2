// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"

#include "tutorial_interfaces/msg/num.hpp" 
#include "rcutils/logging_macros.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:

  rclcpp::TimerBase::SharedPtr timer_;
  //rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
  size_t count_;

  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    //publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("topic", 10);
    timer_ = this->create_wall_timer(
      1s, std::bind(&MinimalPublisher::timer_callback, this));
    
  }

private:
  void timer_callback()
  {
    /*auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());*/
    auto message = tutorial_interfaces::msg::Num();
    message.num = this->count_++;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%ld'", message.num);
    publisher_->publish(message);
  }
};

class Tester : public rclcpp::Node
{
  public:

    rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr abc;                                          // Initializing variables
    rclcpp::TimerBase::SharedPtr func1_timer, func2_timer;
    int counter1;

    Tester() : Node("tester_node")                                                                            // Creating a node
    {
      rcutils_logging_set_logger_level(get_logger().get_name(),RCUTILS_LOG_SEVERITY_DEBUG);                   // Setting up logger configuration
      RCLCPP_DEBUG(get_logger(),"Debug logged");
      RCLCPP_INFO(get_logger(), "Info logged");
      RCLCPP_WARN(get_logger(), "Warning logged");
      RCLCPP_ERROR(get_logger(), "Error logged");
      RCLCPP_FATAL(get_logger(), "Fatal logged");
      abc = this->create_publisher<tutorial_interfaces::msg::Num>("test_publisher",10);                       // Create a publisher
      RCLCPP_INFO(this->get_logger(),"test publisher working");
      func1_timer = this->create_wall_timer(1s, std::bind(&Tester::function1, this));
    }
  
    void function1()
    {
      rclcpp::Clock timer0;
      rclcpp::Time y = timer0.now();
      RCLCPP_INFO(this->get_logger(),"function1 called : %d in %d",counter1,y);
      if(counter1 == 5)
      {
        // call function2 once with a delay of 5 sec
        func2_timer = this->create_wall_timer(5s, std::bind(&Tester::function2, this));

      }
      counter1 ++;
    }

    void function2()
    {
      rclcpp::Clock timer1;
      rclcpp::Time time = rclcpp::Time(10,10,RCL_ROS_TIME);
      RCLCPP_INFO(this->get_logger(),"function 2 called in time : %d",time);
      func2_timer -> cancel();                                                                                 // Cancel the timer after first call 
    }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  if(argc == 1)                                                                    //works when no arguements is provided
  {
    //Tester obj1;
    rclcpp::spin(std::make_shared<Tester>());
  }
  else
  {
    rclcpp::spin(std::make_shared<MinimalPublisher>());                            //works when 1 or more arguements is provided
  }
  rclcpp::shutdown();
  return 0;
}
