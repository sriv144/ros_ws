#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class addtwointsclientnode:public rclcpp::Node
{
    public:
    addtwointsclientnode():Node("add_two_ints_client")
    {
        thread1=std::thread(std::bind(&addtwointsclientnode::calladdtwointsservice,this,3,4));
    }

    void calladdtwointsservice(int a,int b)
    {
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
        while(!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_INFO(this->get_logger(),"Waiting for service to appear...");
        }

        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a=a;
        request->b=b;

        auto future = client->async_send_request(request);

        try{
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(),"%d + %d = %ld",a,b,response->sum);
        }
        catch(const std::exception& e)
        {
            RCLCPP_ERROR(this->get_logger(),"Service call failed");
        }
    }

    private:
        std::thread thread1;
};

int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<addtwointsclientnode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}