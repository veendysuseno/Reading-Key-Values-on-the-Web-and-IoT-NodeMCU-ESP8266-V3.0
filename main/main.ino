// Reading_Button_Value_in_PHP_MySQL_Web.ino
// README.md -> # Reading Button Value in PHP MySQL Web
// Reading Key Values ​​in PHP MYSQL Web

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// WiFi credentials
const char* ssid = "VeendySuseno"; // Masukkan SSID WIFI Name
const char* password = "Admin12345"; // Masukkan Password SSID WIFI

// Pin assignments
const int btn_1 = D2;  // Button pin
const int pinCH_1 = D5;  // Output pin

int CH_1;
String channel;

#define ON LOW  // Active low for button
#define OFF HIGH
boolean data = OFF;
boolean data_last = data;
boolean logika = data;
unsigned long delay_press = 150; // Debounce delay in milliseconds
unsigned long delay_press_last = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(btn_1, INPUT_PULLUP);  // Use internal pull-up for button
  pinMode(pinCH_1, OUTPUT);  // Set the output pin mode

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi Connected!!!");
  } else {
    Serial.println("WiFi Connection Failed!!!");
  }
}

void loop() {
  // Debounce button press
  if (millis() - delay_press_last > delay_press) { 
    data = digitalRead(btn_1);
    if (data != data_last) {
      if (data == ON) {
        logika = !logika;
        channel = "CH_1";  // Set the channel name
        CH_1 = (logika == ON) ? 0 : 1;  // Toggle CH_1 state
      }
      data_last = data;  // Update the last button state
      delay_press_last = millis();  // Reset debounce delay
    }
  }

  // Send HTTP request if WiFi is connected
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://192.168.43.220/veendysuseno/control/proses.php?channel=" + channel + "&CH_1=" + String(CH_1);
    http.begin(url);  // Set the URL

    int httpCode = http.GET();  // Send GET request
    if (httpCode > 0) {
      String payload = http.getString();  // Get the response
      char json[500];
      payload.toCharArray(json, 500);  // Convert the response to char array

      // Parse JSON response
      DynamicJsonDocument doc(200);  // Adjust size according to the JSON response
      deserializeJson(doc, json);

      // Extract values from JSON
      int id = doc["id"];
      String CH_1_status = doc["CH_1"];

      // Control output pin based on the response
      if (CH_1_status == "0") {
        Serial.println("---Channel 1---");
        Serial.println("Status: OFF");
        digitalWrite(pinCH_1, LOW);
      } else {
        Serial.println("---Channel 1---");
        Serial.println("Status: ON");
        digitalWrite(pinCH_1, HIGH);
      }
    } else {
      Serial.println("Error in HTTP request");
    }
    http.end();  // Close HTTP connection
    delay(100);  // Small delay between requests
  }
}
