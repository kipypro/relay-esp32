# ESP32 Relay Control Web Server

This project uses an ESP32 to control relays through a web server. You can toggle the state of each relay using a simple web interface.

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Control up to four relays using an ESP32 microcontroller.
- Simple web interface to toggle the relays on and off.
- mDNS support for easy access via `http://esp32.local`.
- Serial monitor feedback for debugging.

## Hardware Requirements

- ESP32 development board
- 4-channel relay module
- Jumper wires
- Breadboard (optional)

## Software Requirements

- Arduino IDE
- ESP32 board support in Arduino IDE
- CP210x USB to UART Bridge VCP drivers (if required)

## Installation

1. **Set up the Arduino IDE:**
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Add ESP32 board support to the Arduino IDE by following [this guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).

2. **Download the project code:**
   - Clone this repository or download the ZIP file and extract it.

3. **Install the required libraries:**
   - Open the Arduino IDE, go to `Sketch` -> `Include Library` -> `Manage Libraries`.
   - Install the following libraries:
     - `WiFi`
     - `WebServer`
     - `ESPmDNS`

4. **Configure the code:**
   - Open the `esp32_relay_control.ino` file in the Arduino IDE.
   - Replace the placeholders with your WiFi credentials:
     ```cpp
     const char* ssid = "YOUR_SSID";
     const char* password = "YOUR_PASSWORD";
     ```

5. **Upload the code to the ESP32:**
   - Connect your ESP32 to your computer using a USB cable.
   - Select the correct board and port in the Arduino IDE.
   - Click the upload button to flash the code to the ESP32.

## Usage

1. **Connect the relays to the ESP32:**
   - Connect the IN1, IN2, IN3, and IN4 pins of the relay module to GPIO 23, 22, 21, and 19 of the ESP32, respectively.
   - Connect the VCC and GND pins of the relay module to the 5V and GND pins of the ESP32.

2. **Power up the ESP32:**
   - The ESP32 will attempt to connect to the configured WiFi network.

3. **Access the web interface:**
   - Open a web browser and navigate to `http://esp32.local` or the IP address assigned to the ESP32.
   - Use the buttons on the web interface to toggle the relays on and off.

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests with your improvements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
