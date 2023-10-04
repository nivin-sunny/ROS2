#include "rclcpp/rclcpp.hpp"
//#include "tutorial_interfaces/srv/add_three_ints.hpp"        // CHANGE
#include "tutorial_interfaces/srv/shutdown.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("client"); // CHANGE
  
  rclcpp::Client<tutorial_interfaces::srv::Shutdown>::SharedPtr client =                        // CHANGE
    node->create_client<tutorial_interfaces::srv::Shutdown>("service_a"); 
  rclcpp::Client<tutorial_interfaces::srv::Shutdown>::SharedPtr client2 =                        // CHANGE
    node->create_client<tutorial_interfaces::srv::Shutdown>("service_b");                  // CHANGE

  

  auto request = std::make_shared<tutorial_interfaces::srv::Shutdown::Request>();               // CHANGE
  request->req = atoll(argv[1]);// CHANGE

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    if( result.get()->resp==0)
    {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Noda a shutdown SUCCESS!!");
    }
    else{
     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Noda a shutdown FAILED!!"); 
    }
   
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to shutdown Noda a");    // CHANGE
  }

  auto result2 = client2->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result2) ==
    rclcpp::FutureReturnCode::SUCCESS)
 {
    if( result2.get()->resp==0)
    {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Noda b shutdown SUCCESS!!");
    }
    else{
     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Noda b shutdown FAILED!!"); 
    }
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to shutdown Noda b");    // CHANGE
  }

  rclcpp::shutdown();
  return 0;
}