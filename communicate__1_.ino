#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "AUSTRIA_2.4G";
const char* password = "guyzguyzarat1309";

ESP8266WebServer server(80);

// Define the GPIO pins
const int right = 4;  // D2
const int forward = 15; //D8
const int wifiStatusPin = 2; // D4

void setup() {
    Serial.begin(115200);  // Initialize serial communication for debugging
    WiFi.begin(ssid, password);
    pinMode(right, OUTPUT);
    pinMode(forward, OUTPUT);
    pinMode(wifiStatusPin, OUTPUT);

        digitalWrite(right, LOW);
    digitalWrite(forward, LOW);
    digitalWrite(wifiStatusPin, LOW);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());

    if (WiFi.status() == WL_CONNECTED) {
        digitalWrite(wifiStatusPin, HIGH); // Signal that WiFi is connected
    } else {
        digitalWrite(wifiStatusPin, LOW);
    }

    server.on("/", HTTP_GET, []() {
        server.send(200, "text/plain", "Hello from ESP8266!");
    });

    server.on("/data", HTTP_POST, []() {
        String data = server.arg("value");  // Read data from the 'value' parameter
        Serial.print("Received data: ");
        Serial.println(data);

        // Process received data
        if (data == "1") {
            digitalWrite(right, HIGH);
            digitalWrite(forward, LOW);  // Set the pin to HIGH
            Serial.println("Message pin set to HIGH");
        } 
        else if(data == "0")
        {
            digitalWrite(forward, HIGH);
            digitalWrite(right, LOW);  // Set the pin to HIGH
            Serial.println("Message pin set to HIGH");
        }
        else {
            digitalWrite(right, LOW); 
            digitalWrite(forward, LOW);  // Set the pin to LOW
            Serial.println("Message pin set to LOW");
        }

        server.send(200, "text/plain", "Data received");
    });

    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();  // Handle client requests
}
