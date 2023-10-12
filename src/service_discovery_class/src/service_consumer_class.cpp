#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"

class ServiceClientNode : public rclcpp::Node 
{
public:
    ServiceClientNode() : Node("service_client_node") 
    {
        timer_ = create_wall_timer(std::chrono::seconds(5), [this]() {checkAndCallServices();});
    }

private:
    void checkAndCallServices() 
    {
        auto service_names_and_types = rclcpp::Node::get_service_names_and_types();
        static int flag=0;

        // Specify the desired service type
        std::string desired_service_type = "tutorial_interfaces/srv/AddThreeInts";

        for (const auto &service : service_names_and_types) 
        {
            const auto &service_name = service.first;
            const auto &service_types = service.second;

            RCLCPP_INFO(get_logger(), "Service %s available.", service_name.c_str());
            
            // Check if the service matches the desired service type
            if (std::find(service_types.begin(), service_types.end(), desired_service_type) != service_types.end()) 
            {
                auto client = rclcpp::Node::create_client<tutorial_interfaces::srv::AddThreeInts>(service_name);
                    
                auto request = std::make_shared<tutorial_interfaces::srv::AddThreeInts::Request>();
                request->a = 10;
                request->b = 20;
                request->c = 30;

                auto future_result = client->async_send_request(request);
                
                // rclcpp::spin_until_future_complete(shared_from_this(), future_result);
                // RCLCPP_INFO(get_logger(), "inside inside inside");
                // if (future_result.valid() && future_result.get()) 
                // {
                //     auto result = future_result.get();
                //     RCLCPP_INFO(get_logger(), "Service %s Response: %ld", service_name.c_str(), result->sum);
                // } 
                // else 
                // {
                //     RCLCPP_ERROR(get_logger(), "Failed to get response from %s service.", service_name.c_str());
                // }
                
                // if (!client->wait_for_service(std::chrono::seconds(1))) 
                // {
                //     RCLCPP_INFO(get_logger(), "Service %s not available.", service_name.c_str());
                // } 
                // else 
                // {
                
                //}
            }
            else
            {
                //RCLCPP_INFO(get_logger(), "Service %s not available.", service_name.c_str());
            }
        }
    }
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ServiceClientNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
