#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp" // Change message type as needed
#include "tutorial_interfaces/msg/num.hpp"     // CHANGE
#include "tutorial_interfaces/srv/empty.hpp" 
#include "tutorial_interfaces/srv/add_three_ints.hpp" 

class WatchdogNode : public rclcpp::Node {
public:
  WatchdogNode() : Node("watchdog_node"), publisher_alive_(false) {
    // Set the topic you want to monitor (change "target_topic" as needed)
     
    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
        "topic", 10, [this](const tutorial_interfaces::msg::Num::SharedPtr) {
          publisher_alive_ = true;
        });

    // Timer for watchdog checks (adjust the interval as needed)
    watchdog_timer_ = this->create_wall_timer(
        std::chrono::seconds(5), [this]() { checkPublisherStatus(); });

    // rclcpp::Client<tutorial_interfaces::srv::Empty>::SharedPtr client_ =
    // this->create_client<tutorial_interfaces::srv::Empty>("empty_service");
  }
  

private:
  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
  rclcpp::TimerBase::SharedPtr watchdog_timer_;
  bool publisher_alive_;

  void checkPublisherStatus() {
    RCLCPP_INFO(get_logger(), "Publisher node is active");
    if (!publisher_alive_) {
      RCLCPP_ERROR(get_logger(), "Publisher node is unresponsive. Taking corrective action...");
    }
    publisher_alive_=false;
  }


  
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WatchdogNode>());
  rclcpp::shutdown();
  return 0;
}
