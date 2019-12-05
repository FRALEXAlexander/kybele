/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/

// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
// Replace with your network credentials
const char* ssid = "htl-IoT";
const char* password = "iot..2015";

StaticJsonBuffer<1000> databuffer;

#define PIN 2

const int sizeOfLEDs = 136;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(sizeOfLEDs, PIN, NEO_RGB + NEO_KHZ800);


uint32_t color = strip.Color(0, 255, 0);
uint32_t colorOff = strip.Color(0, 0, 0);



long previousMillis = 0;
long interval = 1000;

int potiValue = 0;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Globals
WebSocketsServer webSocket = WebSocketsServer(2000);

void setup() {


   strip.begin();
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

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("load style");
    request->send(SPIFFS, "/style.css", String(), false);
  });
  server.on("/background_earth.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("load background");
    request->send(SPIFFS, "/background_earth.jpg", String(), false);
  });
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("load root");
    request->send(SPIFFS, "/index.html", String(), false);
  });
  server.on("/about.html", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("load about");
    request->send(SPIFFS, "/about.html", String(), false);
  });
  server.on("/data.json", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("load style");
    request->send(SPIFFS, "/data.json", String(), false);
  });

  strip.show();

// Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
  
  // Start server
  server.begin();
}

void handleText(uint8_t num, uint8_t* payload) {
  String str = (char*)payload;
  Serial.print("Command: ");
  Serial.println(str);

  JsonObject& root = databuffer.parseObject(payload);


  int len = root["len"];
  
 
  
  String RedS = root["rgb"][0];
  int red = RedS.toInt();
  String GreenS = root["rgb"][1];
  int green = GreenS.toInt();
  String BlueS = root["rgb"][2];
  int blue = BlueS.toInt();
  String state = root["state"];

  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);
  
  uint32_t color;
  if (state == "on") {
    color = strip.Color(green, red, blue);

  } else {
    color = colorOff;

  }

  for (int i = 0; i < len; i++) {
        String t = root["country"][i];
          strip.setPixelColor(root["country"][i], color);
        Serial.println(t);
  }
  databuffer.clear();
  strip.show();
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
