#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Hadid.Techno";
const char* password = "0r1g4m1m4s3t3r";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.print("Conecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
 if((WiFi.status() == WL_CONNECTED)){

    HTTPClient http;
    WiFiClient wifi;

    http.begin(wifi, "http://192.168.43.243/Skut_Bandung/public/api/user/1");
    int httpCode = http.GET();
     yield();
    if (httpCode > 0){
      
      char json[1000];
      String payload = http.getString();
      payload.toCharArray(json, 1000);
      StaticJsonDocument<200> doc;
      deserializeJson(doc, json);
      Serial.println(payload);
     
      http.end();
      delay(10000);
    }
    else
    {
      Serial.println("Connection lost");
    }  
  }
  else{
    Serial.println("Connection lost");
    
  }
  
  

}
