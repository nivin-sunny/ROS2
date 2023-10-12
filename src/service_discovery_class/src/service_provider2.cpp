#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"
#include <memory>

void multiply_service_request(
    const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,
    std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response> response)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld" " c: %ld",
                request->a, request->b, request->c);
    response->sum = request->a * request->b * request->c;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);   
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("service_server2");

    auto server = node->create_service<tutorial_interfaces::srv::AddThreeInts>("three_ints_operation", &multiply_service_request);

    RCLCPP_INFO(node->get_logger(), "Service 'three_ints_operation' is ready for multiplication.");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}