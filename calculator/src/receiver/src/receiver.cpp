#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include<iostream>
#include<vector>
using namespace std;
using std::placeholders::_1;
class ReceiverNode:public rclcpp::Node{
    vector<int> result;
    int count =0;
    private:
        int needType;
        int num1,num2;
        char type;
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr num1_subscription_;
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr num2_subscription_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr char_subscription_;
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr NeedType_subscription_;
    public:
        ReceiverNode():Node("Receiver_node"){
            num1_subscription_ = this->create_subscription<std_msgs::msg::Int32>("num1_topic",10,std::bind(&ReceiverNode::num1_callback,this,_1));
            num2_subscription_ = this->create_subscription<std_msgs::msg::Int32>("num2_topic",10,std::bind(&ReceiverNode::num2_callback,this,_1));
            char_subscription_ = this->create_subscription<std_msgs::msg::String>("char_topic",10,std::bind(&ReceiverNode::char_callback,this,_1));
            NeedType_subscription_ = this->create_subscription<std_msgs::msg::Int32>("NeedType_topic",10,std::bind(&ReceiverNode::NeedType_callback,this,_1));
        }
        void num1_callback(const std_msgs::msg::Int32::SharedPtr msg){
            num1 = msg->data;
            cout<<"I received num1: "<<msg->data<<endl;
        }
        void num2_callback(const std_msgs::msg::Int32::SharedPtr msg){
            num2 = msg->data;
            cout<<"I received num2: "<<msg->data<<endl;
        }
        void char_callback(const std_msgs::msg::String::SharedPtr msg){
            type = msg->data[0];
            cout<<"I received char: "<<msg->data<<endl;
        }
        void NeedType_callback(const std_msgs::msg::Int32::SharedPtr msg){
            needType = msg->data;
            if(needType == 1 || needType == 2){
                if(type == '+'){
                    result.push_back(num1+num2);
                    count++;
                }
                else if(type == '-'){
                    result.push_back(num1-num2);
                    count++;
                }
                else if(type == '*'){
                    result.push_back(num1*num2);
                    count++;
                }
                else if(type == '/'){
                    result.push_back(num1/num2);
                    count++;
                }
            }
            else if(needType == 3){
                cout<<"History: ";
                for(int i=0;i<count;i++){
                    cout<<result[i]<<" ";
                }
                
            }
            else if(needType == 4){
                result.clear();
                count = 0;
            }
          
        }

};
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ReceiverNode>());
    rclcpp::shutdown();
    return 0;
}
