# ESP32 Logger

A lightweight logging library for ESP32 projects. This library provides an easy-to-use interface for logging messages with different log levels, making debugging and monitoring ESP32 applications more efficient.

## Features

- Supports multiple log levels: `Error`, `Info`, and `Debug`.
- Configurable output stream (e.g., Serial).
- Lightweight and optimized for ESP32.
- Compatible with both Arduino and ESP-IDF frameworks.

## Installation

### Using PlatformIO
1. Add the following to your `platformio.ini` dependencies:
   ```ini
   lib_deps =
       https://github.com/crack-byte/esp32-log.git
2. Build and upload your project as usual.

### Manual Installation
1. Clone this repository:
   ```bash
        git clone https://github.com/crack-byte/esp32-log.git
   ```
2. Include this into your project directory.

## Supported Frameworks and Platforms
1.  `Frameworks`: Arduino, ESP-IDF
2.  `Platforms`: ESP32 (tested only on ESP32-S3)

## Note
This library has been tested only on the `ESP32-S3` using PlatformIO. Compatibility with other `ESP32` variants is not guaranteed at this time.