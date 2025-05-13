#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
enum class LogLevel
{
    Error,
    Info,
    Debug
};
class Logger
{
public:
    void init(HWCDC *output);
    void log(LogLevel logLevel, const char *message, ...);
    void log(const char *message, ...);
    void print(const char *logLine);
    void initTimeInfo();

private:
    HWCDC *_output = nullptr;
    struct tm timeinfo;
    void printEoL();
};

#endif