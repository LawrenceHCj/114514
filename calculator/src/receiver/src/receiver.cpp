
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include <iostream>
#include <vector>

using namespace std;

class ReceiverNode : public rclcpp::Node
{
public:
    ReceiverNode() : Node("Receiver_node"), num1(0), num2(0), count(0), needType(0), type('+')
    {
        // 创建订阅者
        num1_subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "num1_topic", 10, std::bind(&ReceiverNode::num1_callback, this, std::placeholders::_1));
        num2_subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "num2_topic", 10, std::bind(&ReceiverNode::num2_callback, this, std::placeholders::_1));
        char_subscription_ = this->create_subscription<std_msgs::msg::String>(
            "char_topic", 10, std::bind(&ReceiverNode::char_callback, this, std::placeholders::_1));
        NeedType_subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "NeedType_topic", 10, std::bind(&ReceiverNode::NeedType_callback, this, std::placeholders::_1));
    }

private:
    // 处理 num1 订阅消息
    void num1_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        num1 = msg->data;
        cout << "Received num1: " << num1 << endl;
    }

    // 处理 num2 订阅消息
    void num2_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        num2 = msg->data;
        cout << "Received num2: " << num2 << endl;
    }

    // 处理 char 订阅消息
    void char_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        type = msg->data[0];  // 假设只发送一个字符表示操作符
        cout << "Received char: " << type << endl;
    }

    // 处理 NeedType 订阅消息
    void NeedType_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        needType = msg->data;
        
        if (needType == 1)  // 计算
        {
            int result = 0;
            if (type == '+')
            {
                result = num1 + num2;
            }
            else if (type == '-')
            {
                result = num1 - num2;
            }
            else if (type == '*')
            {
                result = num1 * num2;
            }
            else if (type == '/')
            {
                if (num2 != 0)
                    result = num1 / num2;
                else
                    cout << "Error: Division by zero!" << endl;
            }

            results.push_back(result);
            count++;
            cout << "Result: " << result << endl;
        }
        else if (needType == 2)  // 显示历史
        {
            if (results.empty()) {
                cout << "No history available." << endl;
            } else {
                cout << "History: ";
                for (int i = 0; i < count; i++)
                {
                    cout << results[i] << " ";
                }
                cout << endl;
            }
        }
        else if (needType == 3)  // 清除历史
        {
            results.clear();
            count = 0;
            cout << "History cleared!" << endl;
        }
    }

    // 订阅者
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr num1_subscription_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr num2_subscription_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr char_subscription_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr NeedType_subscription_;

    // 数据成员
    int num1, num2, needType, count;
    char type;
    vector<int> results;  // 存储计算结果的历史
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ReceiverNode>());
    rclcpp::shutdown();
    return 0;
}
