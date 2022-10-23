#ifndef _LOGGING_H_
#define _LOGGING_H_
#include <string>

/**
 * @brief 
 * #define PRINT(x)	printf("%s = %d\r\n", #x, x)   #主要用于把参数转为字符串
 *                                                 ##：用于将两个对象连接到一起
 */
class Logger;

#define LOG_ERROR(format, ...) \
    if(Logger::LogError <= Logger::getLogLevel()) \
        Logger().write(Logger::LogError, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)

#define LOG_WARNING(format, ...) \
    if(Logger::LogWarning <= Logger::getLogLevel()) \
        Logger().write(Logger::LogWarning, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)

#define LOG_DEBUG(format, ...) \
    if(Logger::LogDebug <= Logger::getLogLevel()) \
        Logger().write(Logger::LogDebug, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)


//
// Created by 18781811841 on 2022/7/19.
//
// #include<stdlib.h>
// #include <stdio.h>

// #ifndef VIDEOTOOLS_LOG_H
// #define VIDEOTOOLS_LOG_H

// #ifndef  __DEBUG
// #define LOGFUNC(...) ((void)0)
// #else
// #define  LOGFUNC(...)  (printf(__VA_ARGS__))
// #endif

// #define  DEBUG_INFO(format, ...) printf("Info: %s:%d, %s " format "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);
// #endif //VIDEOTOOLS_LOG_H





class Logger
{
public:
    enum LogLevel
    {
        LogError,
        LogWarning,
        LogDebug
    };

    Logger();
    ~Logger();

    static void setLogFile(std::string file);
    static std::string getLogFile();
    static void setLogLevel(LogLevel level);
    static LogLevel getLogLevel();

    void write(LogLevel level, const char* file, const char* func,
                                int line, const char* format, ...);

private:
    char mData[4096] ;
    char* mCurPtr;
    LogLevel mThisLogLevel;

    static LogLevel mLogLevel;
    static std::string mLogFile;
    static bool mIsStdout;
};

#endif //_LOGING_H_