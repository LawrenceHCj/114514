#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include <iostream>

using namespace std;

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode() : Node("Publisher_node"), num1(0), num2(0), type('+'), needType(0)
    {
        // 创建发布者
        num1_publisher_ = this->create_publisher<std_msgs::msg::Int32>("num1_topic", 10);
        num2_publisher_ = this->create_publisher<std_msgs::msg::Int32>("num2_topic", 10);
        char_publisher_ = this->create_publisher<std_msgs::msg::String>("char_topic", 10);
        NeedType_publisher_ = this->create_publisher<std_msgs::msg::Int32>("NeedType_topic", 10);
    }

    void setCalculationParams(int num1, int num2, char type, int needType)
    {
        this->num1 = num1;
        this->num2 = num2;
        this->type = type;
        this->needType = needType;
    }

    void publishMessages()
    {
        auto int_message1 = std_msgs::msg::Int32();
        auto int_message2 = std_msgs::msg::Int32();
        auto char_message = std_msgs::msg::String();
        auto NeedType_message = std_msgs::msg::Int32();

        int_message1.data = num1;
        int_message2.data = num2;
        char_message.data = string(1, type);  // 转换 char 为 string 发送
        NeedType_message.data = needType;

        // 发布消息
        if(needType == 1){num1_publisher_->publish(int_message1);
        num2_publisher_->publish(int_message2);
        char_publisher_->publish(char_message);
        NeedType_publisher_->publish(NeedType_message);

        std::cout << "Published: " << num1 << " " << num2 << " " << type << " " << needType << std::endl;}
        else{
            NeedType_publisher_->publish(NeedType_message);
        }
    }

private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr num1_publisher_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr num2_publisher_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr char_publisher_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr NeedType_publisher_;

    int num1, num2, needType;
    char type;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto publisher_node = std::make_shared<PublisherNode>();

    // 设置初始的数值和计算类型
    publisher_node->setCalculationParams(10, 5, '+', 1);

    while (rclcpp::ok())
    {
        // 提示用户输入
        std::cout << "Enter the parameters for publishing:" << std::endl;
        std::cout << " Enter need type (1: Calculate, 2: History, 3: Clear History)" << std::endl;

        int num1, num2, needType;
        char type;
        std::cin >> needType;
        if(needType ==1){std::cout << "Enter num1 and num2: ";
        std::cin >> num1 >> num2;
        std::cout << "Enter calculation type (+, -, *, /): ";
        std::cin >> type;}
        
        

        // 更新参数
        publisher_node->setCalculationParams(num1, num2, type, needType);

        // 发布消息
        publisher_node->publishMessages();

        // 处理 ROS 事件循环
        rclcpp::spin_some(publisher_node);
    }

    rclcpp::shutdown();
    return 0;
}
