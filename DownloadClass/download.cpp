/*
 * @Author: your name
 * @Date: 2021-02-04 21:52:14
 * @LastEditTime: 2021-02-05 10:18:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\DownloadClass\download.cpp
 */
#include <iostream>
#include <thread>
#include <unistd.h>
#include <functional>



void CallBackTest() {
    std::cout << "callback test " << std::endl;

}



class Download
{
private:
    std::string _url;
    std::thread  download;
    std::function<void()> _download_callback;
    
public:
    Download(std::string url):_url(url) {
        std::cout << " init url : " << _url << std::endl;
        download = std::thread([&]  {
            this->DownloadThread();
        });
        download.detach();
    }
    
    void DownloadThread() {
        while (1) {
            std::cout << " downloading , please wait ..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if(_download_callback) {
                _download_callback();
            }
        }
    }

    void SetDownLoadEndCallBack(std::function<void()> callback) {
        _download_callback = callback;
    }

    void end() {
        std::cout << " endl " << std::endl;
    }

    ~Download(){}
};



void CallBack() {
    std::cout << " CallBack ... " << std::endl;
}

int main(void) 
{
    Download test("https://123.cpm");
    test.SetDownLoadEndCallBack(CallBack);
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
    test.end();
    
    return 0;
}

 
