/*
 * @Author: your name
 * @Date: 2021-01-24 15:15:52
 * @LastEditTime: 2021-01-25 00:11:54
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
#include <mutex>

using namespace std;

class Mythread
{
private:
    std::string _name;
    std::uint8_t _age = 0;
    std::mutex  _thread_lock;
    std::condition_variable _notify_lock;
    std::thread _my_thread1;
    std::thread _my_thread2;
    
public:
    Mythread(std::string name, std::uint8_t age):_name(name), _age(age) {
        std::cout << "name :  " << _name <<  std::endl; 
        std::cout << "age  :  " << unsigned(_age) << std::endl; 
    }
    
    void RunThread1() {
        while (1) {
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            std::cout << "RunThread1  _age =  " << unsigned(_age) << std::endl;
            _age++;
            if(_age%2==0) {
                _notify_lock.notify_all();
            }
        }
    }

    void RunThread2() {
        while (1) {
            std::unique_lock<std::mutex> block_handler_lock(_thread_lock);
            _notify_lock.wait_for(block_handler_lock, std::chrono::milliseconds(2000));
            std::cout << "RunThread2  _age = " << unsigned(_age) << std::endl;
            _age++;
        }
    }
    
    void start_thread1() {
        _my_thread1 = std::thread([&]  {
            this->RunThread1();
        });
    }

    void start_thread2() {
        _my_thread2 = std::thread([&]  {
            this->RunThread2();
        });
    }

    ~Mythread() {
        _my_thread1.joinable();
        _my_thread2.joinable();
    }
};


int main() {
    std::cout << "cpp test" << std::endl;
    uint8_t nn = 25;
    Mythread Test("nongpubin", nn);
    Test.start_thread1();
    Test.start_thread2();

    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        // std::cout << "nn = " << unsigned(nn) << std::endl;
        // nn++;
         
    }
 
    return 0;
}
