/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/

// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <WebSocketsServer.h>
// Replace with your network credentials
const char* ssid = "htl-IoT";
const char* password = "iot..2015";

long previousMillis = 0;
long interval = 1000;

int potiValue = 0;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Globals
WebSocketsServer webSocket = WebSocketsServer(2000);

void setup() {

 pinMode(36, INPUT);
  pinMode(26, OUTPUT);
  digitalWrite(26, LOW);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);

  
  // Serial port for debugging purposes
  Serial.begin(115200);
 
  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("load root");
    request->send(SPIFFS, "/index.html", String(), false);
  });

// Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
  
  // Start server
  server.begin();
}

void handleText(uint8_t num, uint8_t* payload) {
  String str = (char*)payload;
  Serial.print(str);
  if (str == "R") {
    Serial.println("RGB LED RED");
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(16, LOW);
  } else if (str == "G") {
    Serial.println("RGB LED GREEN");
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(16, LOW);
  } else if (str == "B") {
    Serial.println("RGB LED BLUE");
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(16, HIGH);
  } else if (str == "getPoti") {
    String val = String("poti")+String(potiValue);
    Serial.println(val);
    webSocket.sendTXT(num, val);
  }
}

// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num,
                      WStype_t type,
                      uint8_t * payload,
                      size_t length) {

  // Figure out the type of WebSocket event
  switch (type) {

    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        Serial.println(ip.toString());
      }
      break;

    // Echo text message back to client
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload);
      //webSocket.sendTXT(num, payload);
      handleText(num, payload);
      break;

    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}

void loop() {
 // Look for and handle WebSocket data
  webSocket.loop();

  if (millis() - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = millis();
    //Serial.println(analogRead(36));

    potiValue = analogRead(36);

  }
}
