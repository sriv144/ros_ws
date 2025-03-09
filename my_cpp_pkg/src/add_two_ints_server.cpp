#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class addtwointsservernode:public rclcpp::Node
{
    public:
    addtwointsservernode():Node("add_two_ints_server")
    {
        server=this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints",std::bind(&addtwointsservernode::callback,this,std::placeholders::_1,std::placeholders::_2));
        RCLCPP_INFO(this->get_logger(),"Add Two Ints Server has been started.");
    }
    private:

    void callback(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,const std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
    {
        response->sum=request->a+request->b;
        RCLCPP_INFO(this->get_logger(),"%ld + %ld = %ld",request->a,request->b,response->sum);
    }

    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server;
};

int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<addtwointsservernode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}