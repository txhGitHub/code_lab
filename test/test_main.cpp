#include <iostream>
#include<pthread.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <queue>

#include "GlobalConfiguration.h"
#include "yaml-cpp/yaml.h"
#include "stdio.h"
#include "Logging.h"
#include "ThreadPool.h"
#include "Timer.h"
#include "RtspServer.h"
#include "farmXML.h"




std::mutex mtx;
//前置声明一般与A类声明的顺序有关。

int main(int argc, char* argv[])
{    
    static std::queue<std::string> words;
    for(int i = 0; i < 10; i++)
    {
        static int count = 0;
        std::thread thread{ [] {
            // std::lock_guard<std::mutex> tem(mtx);
            count = count + 1;
            words.push(std::to_string(count));
            std::cout << "api: " << GlobalConfiguration::GetInstance()->getYamlConfig()["v"].as<std::string>()  << std::endl;
           ;} };
        thread.detach();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << " size: " << words.size()  << std::endl; //< 2
    while (!words.empty())
    {
        std::cout << " i-: " << words.front() << std::endl; //< 2
        words.pop();
    }
    
    return 0;
}
