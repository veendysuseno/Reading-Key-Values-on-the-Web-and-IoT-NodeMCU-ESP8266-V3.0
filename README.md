# Reading Key Values on the Web and IoT NodeMCU ESP8266 V3.0

This project demonstrates how to use an IoT-based system to read button values through a web interface using PHP and MySQL, with an ESP8266 NodeMCU as the microcontroller. The button state is stored in a MySQL database, and an LED is toggled based on the button input.

## Project Overview

- **Project Type**: IoT Project - Reading Button Values via Web
- **Microcontroller**: ESP8266 NodeMCU (Lolin) V3.0

## Hardware Components

- **Nodemcu Lolin**
- **Baseboard or Breadboard** (optional)
- **Push Button**
- **LED**
- **Resistors**
- **Jumper Wires**

## Wiring

- **Push Button**: Connected to pin `D2` (GPIO 4) on the NodeMCU.
- **LED**: Connected to pin `D5` (GPIO 14) on the NodeMCU.

## Database Setup

1. **Database Name**: `demo`
2. **Table Name**: `tb-control`

### Table Structure:

Make sure to create the table with the appropriate structure. The table should be initialized with a starting value of `0` because the system runs an `UPDATE` query to toggle the button state, which requires an initial value in the table.

> **Tip**: You can refer to the attached photo of the database structure (not provided in this README).

## How It Works

- The ESP8266 reads the state of the push button and updates the button status in the MySQL database.
- An LED connected to the NodeMCU is toggled based on the state of the button read from the web interface.
- The system uses a PHP backend to process the button state and store it in the database.

## Usage Instructions

1. **Setup the Hardware**:
   - Connect the push button to pin `D2` and the LED to pin `D5` of the NodeMCU, as described in the wiring section.

2. **Database Configuration**:
   - Create the database and table using the given structure.
   - Insert an initial value of `0` into the table to allow the `UPDATE` query to function.

3. **Code Configuration**:
   - Update the WiFi credentials in the code to match your network (`ssid` and `password`).
   - Modify the IP address and paths in the HTTP requests to match your PHP web server and the directory where the `proses.php` file is located.

4. **Run the System**:
   - Flash the code to your NodeMCU using the Arduino IDE.
   - Once powered, the NodeMCU will connect to your WiFi, monitor the button state, and send the data to the web server.

## Example HTTP Request

The following is an example of an HTTP GET request sent by the NodeMCU to update the button state:

[http://192.168.43.220/veendysuseno/control/proses.php?channel=CH_1&CH_1=1](http://192.168.43.220/veendysuseno/control/proses.php?channel=CH_1&CH_1=1)


Ensure the IP address matches your local web server’s IP and the file path points to the correct location of your PHP script.

## Happy Tinkering!

Enjoy experimenting with this project and don’t hesitate to customize it to fit your needs. Remember to set up your database properly for everything to work smoothly!

**Greetings to all of us**,  
@veendysuseno
