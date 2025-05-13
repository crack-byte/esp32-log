/**
 * @author Abhishek Purohit
 * @brief Simple example of using the Logger class
 * @details This example demonstrates how to use the Logger class to log messages
 *          with different log levels (Error, Info, Debug) and format strings.
 */

#include <Arduino.h> // Include Arduino library for Serial communication if needed
#include "Logger.h"

// Create a Logger instance
Logger logger;

void setup() {
    // Initialize Serial communication
    Serial.begin(115200);
    while (!Serial) {
        delay(10); // Wait for Serial to initialize
    }

    // Initialize the logger with Serial as the output
    logger.init(&Serial);

    // Log some messages with different log levels
    logger.log(LogLevel::Info, "Logger initialized successfully.");
    logger.log("Logger initialized successfully: %s", "true");
    logger.log(LogLevel::Debug, "Debugging mode is active.");
    logger.log(LogLevel::Error, "An error occurred while initializing.");
}

void loop() {
    // Log a message in the loop
    logger.log("This is a periodic log message.");
    delay(2000); // Wait for 2 seconds
}