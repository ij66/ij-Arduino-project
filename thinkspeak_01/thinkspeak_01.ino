#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros
#define sensor1 A0

int nilai;
int statusCode;

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
WiFiClient  client;

// Weather station channel details
unsigned long weatherStationChannelNumber = SECRET_CH_ID_WEATHER_STATION;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
const char * myReadAPIKey = SECRET_READ_APIKEY;

void setup() {
  
  Serial.begin(115200);      // Initialize serial 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA);
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  pinMode(sensor1, INPUT);

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }
}

void loop() {
  statusCode = ThingSpeak.readMultipleFields(weatherStationChannelNumber);
  nilai= analogRead(sensor1);
  Serial.println(nilai);
    
    if(statusCode == 200)
    {

      Serial.println("SUKSES");
      int led = ThingSpeak.readIntField(weatherStationChannelNumber,2,myReadAPIKey); // Field 1
      Serial.println(led);
      ThingSpeak.writeField(weatherStationChannelNumber,1,nilai,myWriteAPIKey);
      delay (500);
    }
}
