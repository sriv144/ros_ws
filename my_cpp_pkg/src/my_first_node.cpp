#include "rclcpp/rclcpp.hpp"

class mynode:public rclcpp::Node
{
    public:
    mynode():Node("cpp_test")
    {
        RCLCPP_INFO(this->get_logger(),"Hello cpp node");

        timer_ = this->create_wall_timer(std::chrono::seconds(1),std::bind(&mynode::timer_callback,this));
    }
    private:

        void timer_callback()
        {
            counter++;
            RCLCPP_INFO(this->get_logger(),"Hello %d",counter);
        }

        rclcpp::TimerBase::SharedPtr timer_;
        int counter = 0;
};

int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<mynode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}