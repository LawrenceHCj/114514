#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include<iostream>
using std::placeholders::_1;
using namespace std;
using namespace std::chrono_literals;
class PublisherNode : public rclcpp::Node
{
    public:
        PublisherNode(): Node("Publisher_node"){
            num1_publisher_ = this->create_publisher<std_msgs::msg::Int32>("num1_topic",10);
            num2_publisher_ = this->create_publisher<std_msgs::msg::Int32>("num2_topic",10);
            char_publisher_ = this->create_publisher<std_msgs::msg::String>("char_topic",10);
            NeedType_publisher_ = this->create_publisher<std_msgs::msg::Int32>("NeedType_topic",10);
            flag_ = false;
        }



        void PublishNumber(int num1,int num2,int type){
                auto int_message1 = std_msgs::msg::Int32(),int_message2 = std_msgs::msg::Int32();
                auto char_message = std_msgs::msg::String();
                auto NeedType_message = std_msgs::msg::Int32();
                int_message1.data = num1;
                int_message2.data = num2;
                char_message.data = type;
                NeedType_message.data = needType;
                NeedType_publisher_->publish(NeedType_message);
                num1_publisher_->publish(int_message1);
                num2_publisher_->publish(int_message2); 
                char_publisher_->publish(char_message);
        }

        void publishNeed(){
            // if(!flag_){
                std::cout<<"choose your need"<<std::endl;
                cout<<"1.getNumber"<<endl<<"2.type"<<endl<<"3.check history"
                <<endl<<"4.delete history"<<endl;
                int choice;
                cin>>choice;
                if(choice==1){
                    needType = 1;
                    Need1();
                    Need2();
                    PublishNumber(num1,num2,type);
                    
                }
                else if(choice==2){
                    needType = 2;
                    Need2();
                    Need1();
                    PublishNumber(num1,num2,type);
                }
                else if(choice==3){
                    needType = 3;
                    auto NeedType_message = std_msgs::msg::Int32();
                    NeedType_message.data = needType;
                    NeedType_publisher_->publish(NeedType_message);
                    
                }
                else if(choice==4){
                    needType = 4;
                    auto NeedType_message = std_msgs::msg::Int32();
                    NeedType_message.data = needType;
                    NeedType_publisher_->publish(NeedType_message);

                }
                
                else{
                    cout<<"Invalid choice"<<endl;
                }
                // flag_ = true;
            // }

        }
    private:
        int needType;
        int num1,num2;
        char type;
        void Need1(){
            std::cout<<"Enter the number"<<endl;
           
            cin>>num1>>num2;
            
        }
        void Need2(){
            cout<<"choose your calculate type"<<endl;
            bool flag = true;
            cin>>type;
            while(flag){if(type=='+'){
                flag = false;
            }
            else if(type=='-'){
               flag = false;
            }
            else if(type=='*'){
                flag = false;
            }
            else if(type=='/'){
                flag = false;
            }
            else{
                cout<<"Invalid type Reput"<<endl;
                flag = true;
            }
            }
            
        }
       

        

        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr num1_publisher_;
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr num2_publisher_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr char_publisher_;
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr NeedType_publisher_;
        bool flag_;
};
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto publisher_node=(std::make_shared<PublisherNode>());
    publisher_node->publishNeed();
    rclcpp::spin(publisher_node);
    rclcpp::shutdown();
    return 0;
}