#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<rclcpp::Node>("add_two_ints_client_noop");

    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    while (!client->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_WARN(node->get_logger(), "service not available, waiting again...");
    }

    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 13;
    request->b = 40;

    auto future=client->async_send_request(request);
    if(rclcpp::spin_until_future_complete(node,future)==rclcpp::FutureReturnCode::SUCCESS)
    {
        auto response=future.get();
        RCLCPP_INFO(node->get_logger(),"%ld + %ld = %ld",request->a,request->b,response->sum);
    }
    else
    {
        RCLCPP_ERROR(node->get_logger(),"Service call failed.");
    }

    rclcpp::shutdown();
    return 0;
}