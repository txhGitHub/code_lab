#include<ctime>
#include<string>
#include <iostream>

#define MY_TIMEV    struct timeval
class Timer
{
    MY_TIMEV startT;
    std::string label;//计时内容：有多个计时的时候用于区分
    bool isEnd;//是否已经手动结束计时
    //clock（）获取获取的时候cpu的使用时间
public:
    Timer(std::string name = "Time")//创建时开始计时
    {
        startT = clockGetTime(); 
        label = name;
        isEnd = false;
    }

    ~Timer()//自动结束计时//对象被销毁时自动结束计时
    {
        if (!isEnd)
        {
            MY_TIMEV endT = clockGetTime();
            int endtime = (endT.tv_sec*1000 + endT.tv_usec/1000) - (startT.tv_sec*1000 + startT.tv_usec/1000);
            std::cout << label << " execution time" << ": " <<  (endtime/1000.0)<< "s" <<std::endl;		//s为单位
        }
    }

    void End()//手动结束//手动控制在任意位置处结束计时
    {
        MY_TIMEV endT = clockGetTime();
        int endtime = (endT.tv_sec*1000 + endT.tv_usec/1000) - (startT.tv_sec*1000 + startT.tv_usec/1000);
        std::cout << label << " execution time" << ": " << (endtime/1000.0)<< "s" << std::endl;		//s为单位
        isEnd = true;
    }

    MY_TIMEV clockGetTime(clockid_t _tclock_id = CLOCK_MONOTONIC)
    {
        struct timespec stTime;
        //该函数的时间精确到纳秒级别
        clock_gettime(_tclock_id, &stTime);
        MY_TIMEV stRet;
        stRet.tv_sec = stTime.tv_sec;
        stRet.tv_usec = stTime.tv_nsec/1000;
        return stRet;	
    }
};
