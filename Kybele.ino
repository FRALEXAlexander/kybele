//--------------------
//libraries
//--------------------
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <SocketIoClient.h>

//--------------------
// WIFI
//--------------------
const char* ssid = "htl-IoT";
const char* password = "iot..2015";
//--------------------
//Websocket Server
//--------------------
const char* serverIP = "10.68.200.200";
const int serverPort  = 2601;
//--------------------
//Variables
//--------------------
bool connection = false;
//--------------------
//Objects
//--------------------
SocketIoClient webSocket;
StaticJsonBuffer<1000> databuffer;




#define PIN 2

const int sizeOfLEDs = 136;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(sizeOfLEDs, PIN, NEO_RGB + NEO_KHZ800);


uint32_t color = strip.Color(0, 255, 0);
uint32_t colorOff = strip.Color(0, 0, 0);


//--------------------
//Setup
//--------------------
void setup() {
  ESP.wdtDisable();
  strip.begin();
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print('.');
  }
  Serial.println();
  Serial.println("Connected to wifi");

  WebSocketSetup();


  strip.show();
}


//--------------------
//Loop
//--------------------
void loop() {

  WebSocketLoop();

  if (!connection) {
    return;
  };





}
//--------------------
//WebSocket
//--------------------
void WebSocketSetup() {
  webSocket.on("connect", onConnect);
  webSocket.on("disconnect", onDisconnect);
  webSocket.on("ESPsetCountry", onESPsetCountry);
  webSocket.begin(serverIP, serverPort);

}
void WebSocketLoop() {



  webSocket.loop();

}
void onConnect(const char * payload, size_t length) {
  Serial.print("connected");
  webSocket.emit("setID", "\"ESP\"");
  delay(1000);
  connection = true;
}
void onDisconnect(const char * payload, size_t length) {
  Serial.print("disconnected");

  connection = false;
}
void onESPsetCountry(const char * payload, size_t length) {
  Serial.println("ESPsetCountry");

 
  
  JsonObject& root = databuffer.parseObject(payload);


  int len = root["length"];
  
 
  
  String RedS = root["rgb"][0];
  int red = RedS.toInt();
  String GreenS = root["rgb"][1];
  int green = GreenS.toInt();
  String BlueS = root["rgb"][2];
  int blue = BlueS.toInt();
  String state = root["state"];


 
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
