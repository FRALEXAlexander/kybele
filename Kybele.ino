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
const char* serverIP = "10.68.131.7";
const int serverPort  = 2200;
//--------------------
//Variables
//--------------------
bool connection = false;
//--------------------
//Objects
//--------------------
SocketIoClient webSocket;
StaticJsonBuffer<200> databuffer;




#define PIN 2

const int sizeOfLEDs = 100;

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

int countryLEDs [150][15] ;

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

  int counter = 0;


  int i = 0;

  //Alaska
  for (i = counter; i < 2; i++) {
    countryLEDs[4][i] = counter;
    counter++;
  }

  //Kanada
  for (i = counter; i < 5; i++) {
    countryLEDs[41][i] = counter;
    counter++;
  }

  //USA
  for (i = counter; i < 8; i++) {
    countryLEDs[97][i] = counter;
    counter++;
  }

  //Mexico
  for (i = counter; i < 10; i++) {
    countryLEDs[54][i] = counter;
    counter++;
  }

  //Guatemala
  countryLEDs[28][0] = counter;
  counter++;

  //Panama
  countryLEDs[66][0] = counter;
  counter++;

  //Kuba
  countryLEDs[47][0] = counter;
  counter++;

  //Kolumbien
  countryLEDs[44][0] = counter;
  counter++;

  //Venezuela
  countryLEDs[99][0] = counter;
  counter++;

  //Guyana
  countryLEDs[30][0] = counter;
  counter++;

  //Suriname
  countryLEDs[86][0] = counter;
  counter++;

  //Ecuador
  countryLEDs[20][0] = counter;
  counter++;

  //Peru
  for (i = counter; i < 20; i++) {
    countryLEDs[68][i] = counter;
    counter++;
  }

  //Brasilien
  for (i = counter; i < 23; i++) {
    countryLEDs[14][i] = counter;
    counter++;
  }

  //Bolivien
  countryLEDs[12][i] = counter;
  counter++;

  //Paraguay
  countryLEDs[67][i] = counter;
  counter++;

  //argentinien
  for (i = counter; i < 27; i++) {
    countryLEDs[8][i] = counter;
    counter++;
  }

  //Urugay
  countryLEDs[96][i] = counter;
  counter++;

  //Grönland
  for (i = counter; i < 31; i++) {
    countryLEDs[27][i] = counter;
    counter++;
  }

  //-------------------------------

  //Island
  countryLEDs[36][0] = counter;
  counter++;

  //Irland
  countryLEDs[35][0] = counter;
  counter++;

  //England
  countryLEDs[21][0] = counter;
  counter++;

  //Norwegen
  countryLEDs[62][0] = counter;
  counter++;

  //Schweden
  countryLEDs[77][0] = counter;
  counter++;

  //Finnland
  countryLEDs[22][0] = counter;
  counter++;

  //Baltische Staaten
  countryLEDs[11][0] = counter;
  counter++;

  //Polen
  countryLEDs[70][0] = counter;
  counter++;

  //deutschland
  countryLEDs[19][0] = counter;
  counter++;

  //Niederlande
  countryLEDs[59][0] = counter;
  counter++;

  //Frankreich
  countryLEDs[23][0] = counter;
  counter++;

  //schweiz
  countryLEDs[78][0] = counter;
  counter++;

  //Österreich
  countryLEDs[64][0] = counter;
  counter++;

  //Ungarn
  countryLEDs[95][0] = counter;
  counter++;

  //weißrussland
  countryLEDs[100][0] = counter;
  counter++;

  //Ukraine
  countryLEDs[94][0] = counter;
  counter++;

  //Rumänien
  countryLEDs[72][0] = counter;
  counter++;

  //Bulgarien
  countryLEDs[15][0] = counter;
  counter++;

  //serbien
  countryLEDs[80][0] = counter;
  counter++;

  //Italien
  countryLEDs[37][0] = counter;
  counter++;

  //Griechenland
  countryLEDs[26][0] = counter;
  counter++;

  //spanien
  countryLEDs[83][0] = counter;
  counter++;

  //Portgual
  countryLEDs[71][0] = counter;
  counter++;

  //marokko
  countryLEDs[52][0] = counter;
  counter++;

  //Algrien
  countryLEDs[5][0] = counter;
  counter++;

  //Libyen
  countryLEDs[48][0] = counter;
  counter++;

  //Ägypten
  countryLEDs[3][0] = counter;
  counter++;

  //Sudan
  countryLEDs[85][0] = counter;
  counter++;

  //Tschad
  countryLEDs[90][0] = counter;
  counter++;

  //Niger
  countryLEDs[60][0] = counter;
  counter++;

  //Mali
  countryLEDs[51][0] = counter;
  counter++;

  //Mauretanien
  countryLEDs[53][0] = counter;
  counter++;

  //sahara
  countryLEDs[74][0] = counter;
  counter++;

  //Senegal Gambia
  countryLEDs[79][0] = counter;
  counter++;

  //Guinea
  countryLEDs[29][0] = counter;
  counter++;

  //Coged'ivoire
  countryLEDs[18][0] = counter;
  counter++;

  //Burkina Faso
  countryLEDs[16][0] = counter;
  counter++;

  //Nigeria
  countryLEDs[61][0] = counter;
  counter++;

  //Kamerun
  countryLEDs[40][0] = counter;
  counter++;

  //zentralafrika
  countryLEDs[102][0] = counter;
  counter++;

  //äthopien
  countryLEDs[9][0] = counter;
  counter++;

  //somalia
  countryLEDs[82][0] = counter;
  counter++;

  //kenia
  countryLEDs[43][0] = counter;
  counter++;

  //Uganda
  countryLEDs[93][0] = counter;
  counter++;

  //Tansanuia
  countryLEDs[88][0] = counter;
  counter++;

  //Zaire
  countryLEDs[101][0] = counter;
  counter++;

  //Kongo
  countryLEDs[45][0] = counter;
  counter++;

  //gabun
  countryLEDs[24][0] = counter;
  counter++;

  //Angola
  countryLEDs[6][0] = counter;
  counter++;

  //Sambia
  countryLEDs[75][0] = counter;
  counter++;

  //Mosambik
  countryLEDs[55][0] = counter;
  counter++;

  //simbawe
  countryLEDs[81][0] = counter;
  counter++;

  //Botsuana
  countryLEDs[13][0] = counter;
  counter++;

  //Namibia
  countryLEDs[57][0] = counter;
  counter++;

  //südafrika
  countryLEDs[84][0] = counter;
  counter++;

  //Madagaska
  countryLEDs[49][0] = counter;
  counter++;

  //Jemen
  countryLEDs[39][0] = counter;
  counter++;

  //Oman
  countryLEDs[63][0] = counter;
  counter++;

  //noch nicht fertig, start land:saudi arabien











  /*------------------
    countryLEDs[][i] = counter;
    counter++;

    for (i = counter; i < ; i++) {
    countryLEDs[][i] = counter;
    counter++;
    }

  */



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

  String countryS = root["country"];
  int country = countryS.toInt();
  String RedS = root["rgb"][0];
  int red = RedS.toInt();
  String GreenS = root["rgb"][1];
  int green = GreenS.toInt();
  String BlueS = root["rgb"][2];
  int blue = BlueS.toInt();
  String state = root["state"];

  //  Serial.println(country +);
  //Serial.println(red);
  //Serial.println(green);
  //Serial.println(blue);
  //Serial.println(state);

  databuffer.clear();
  if (state == "on") {
    Serial.println("on");
    uint32_t color = strip.Color(green, red, blue);

    // strip.setPixelColor(country, color);
    
    for (int i = 0; i < 15; i++) {
      if (countryLEDs[country][i] != 0) {
        Serial.print(i+" "+countryLEDs[country][i]);
        strip.setPixelColor(countryLEDs[country][i], color);
      }
    }


  } else if (state == "off") {
    Serial.println("off");

 for (int i = 0; i < 15; i++) {
      if (countryLEDs[country][i] != 0) {
        Serial.print(countryLEDs[country][i]);
        strip.setPixelColor(countryLEDs[country][i], colorOff);
      }


    }

  }
  strip.show();
}
