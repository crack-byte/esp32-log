#include "Logger.h"

void Logger::init(HWCDC *output)
{
    this->_output = output;
}

void Logger::log(LogLevel logLevel, const char *message, ...)
{
    if (this->_output == nullptr)
    {
        return;
    }

    va_list args;
    va_start(args, message);
    char logLine[256];
    vsnprintf(logLine, sizeof(logLine), message, args);
    va_end(args);
    switch (logLevel)
    {
    case LogLevel::Debug:
        this->print("DBG ");
        break;
    case LogLevel::Error:
        this->print("ERROR ");
        break;
    case LogLevel::Info:
        this->print("INFO ");
        break;
    }
    this->print(logLine);
    this->printEoL();
}
void Logger::log(const char *message, ...)
{
    if (this->_output == nullptr)
    {
        return;
    }
    Serial.print(&timeinfo, "[%Y-%m-%d %H:%M:%S] ");
    va_list args;
    va_start(args, message);
    char logLine[256];
    vsnprintf(logLine, sizeof(logLine), message, args);
    va_end(args);
    this->print("INFO ");
    this->print(logLine);
    this->printEoL();
}
void Logger::print(const char *logLine)
{
    if (this->_output == nullptr)
    {
        return;
    }

    this->_output->print(logLine);
}
void Logger::printEoL()
{
    if (this->_output == nullptr)
    {
        return;
    }

    this->_output->println();
}

void Logger::initTimeInfo()
{
    if (this->_output == nullptr)
    {
        return;
    }
    if (!getLocalTime(&timeinfo))
    {
        this->log("Failed to obtain time");
        this->log("Restarting ESP32...");
        ESP.restart();
    }
    else
    {
        this->log("Time initialized");
    }
}