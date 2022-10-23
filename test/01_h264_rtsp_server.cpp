#include <iostream>
#include<pthread.h>
#include <unistd.h>

#include "stdio.h"
#include "Object.h"
#include "Logging.h"
#include "ThreadPool.h"
#include "Timer.h"

int main(int argc, char* argv[])
{
    // if(argc !=  2)
    // {
    //     std::cout<<"Usage: "<<argv[0]<<" <aac file>"<<std::endl;
    //     return -1;
    // }
    //vector初始化大小
    Timer k("test");
    Logger::setLogLevel(Logger::LogWarning);
    long i = 100000000000;

    ThreadPool* threadPool = ThreadPool::createNew(2);
    return 0;
}