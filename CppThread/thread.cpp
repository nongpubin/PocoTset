/*
 * @Author: your name
 * @Date: 2021-01-24 15:15:52
 * @LastEditTime: 2021-01-24 18:28:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\CppThread\thread.cpp
 */

#include <iostream>
#include <thread>
#include <condition_variable>
#include <functional>
#include <thread>
#include <unistd.h>

using namespace std;

class Mythread
{
private:
    std::string _name;
    std::uint8_t _age = 0;
    std::mutex  _thread_lock;
    std::condition_variable _notify_lock;
    std::thread _my_thread;
    
   
public:
    Mythread(std::string name, std::uint8_t age):_name(name), _age(age) {
        std::cout << "name :  " << _name <<  std::endl; 
        std::cout << "age  :  " << unsigned(_age) << std::endl; 
        
    }
    
    void Run() {
        while (1) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "hello >>> " << std::endl;
        }
    }
    
    void start_thread() {
        _my_thread = std::thread(std::bind(&Mythread::Run,this));
        // _my_thread = std::thread([&]{this->Run();});
        // std::thread _my_thread(Run);
    //    auto _my_thread  = [&] { this->Run() ;};
    //    std::thread _my_thread(Run);
        // _my_thread.joinable();
         
    }

    ~Mythread(){}
};


int main() {
    std::cout << "cpp test" << std::endl;
    uint8_t nn = 25;
    Mythread Test("nongpubin", nn);
    // Test.start_thread();
    Test.start_thread();

 
    return 0;
}
