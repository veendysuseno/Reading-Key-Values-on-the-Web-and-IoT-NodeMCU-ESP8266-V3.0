# Reading Button Value in PHP MySQL Web

This project demonstrates how to read the state of a button connected to an ESP8266 NodeMCU and send the button's state to a web server via an HTTP GET request. The web server uses PHP and MySQL to store the data and respond to the ESP8266. Additionally, the web server can return JSON data, which the ESP8266 processes to control output pins.

## Features

- **Button State Monitoring**: The ESP8266 reads the button state (pressed or not pressed).
- **HTTP GET Request**: Button states are sent to a web server as part of an HTTP GET request.
- **Web Integration**: PHP and MySQL are used on the server to process and store the button data.
- **JSON Response Parsing**: The ESP8266 receives a JSON response from the server and parses it to control an output pin.
- **WiFi Connectivity**: The ESP8266 connects to a WiFi network to communicate with the server.

## Components Used

- **ESP8266 NodeMCU**
- **Button (Connected to D2 pin)**
- **LED or Relay (Controlled via D5 pin)**

## Wiring Diagram

- Button: Connect to `D2` and `GND` (using internal pull-up resistor)
- LED/Relay: Connect to `D5` and `GND`

## Requirements

- **Arduino IDE** with the ESP8266 board installed
- **ArduinoJson** library (for JSON parsing)
- **ESP8266WiFi** and **ESP8266HTTPClient** libraries

## Installation

1. **Install ArduinoJson Library**:
   - In the Arduino IDE, go to `Sketch -> Include Library -> Manage Libraries`.
   - Search for "ArduinoJson" and install the latest version.

2. **Install ESP8266 Core**:
   - In Arduino IDE, go to `File -> Preferences`.
   - In the "Additional Boards Manager URLs" field, add this URL: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
   - Then go to `Tools -> Board -> Boards Manager`, search for "esp8266" and install the package.

## Setup

1. **Connect the ESP8266 to your WiFi**:
   - In the code, modify the `ssid` and `password` variables with your WiFi credentials.

2. **Configure the PHP Server**:
   - Upload the `proses.php` script to your server (modify the IP address in the code).
   - Set up a MySQL database to log button data.

3. **Upload the Code**:
   - Connect your ESP8266 to your PC.
   - Open the `.ino` file in the Arduino IDE.
   - Select the correct board and COM port.
   - Upload the code to the ESP8266.

## Code Explanation

- The ESP8266 monitors the button connected to pin `D2`.
- When the button state changes, it toggles the `CH_1` state (on/off).
- The current state is sent to the server using an HTTP GET request, where it is processed by a PHP script.
- The server responds with a JSON object, and the ESP8266 reads the `CH_1` value from the response to control the output pin `D5`.

## Example URL Request

[http://192.168.43.220/veendysuseno/control/proses.php?channel=CH_1&CH_1=1](http://192.168.43.220/veendysuseno/control/proses.php?channel=CH_1&CH_1=1)


## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Authors

- Veendy_Suseno
