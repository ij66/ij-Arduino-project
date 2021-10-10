#include <WiFi.h>
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

const char* ssid = "realmi 5i";
const char* password = "12345678";
char jsonOutput[128];

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

    HTTPClient client;

    client.begin("https://jsonplaceholder.typicode.com/posts";
    client.addHeader("Content-Type", "application/json");

    const size_t CAPACITY = JSON_OBJECT_SIZE(3);
    StaticJsonDocument<CAPACITY> doc;

    JsonObject obj = doc.to<JsonObject>();
    object["title"] = "It's ij";

    serializeJson(doc, jsonoutput);

    int httpCode = client.POST(String(jsonOutput)); 

    if (httpCode > 0){
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);

      client.end();
    
    }
    else
    {
      Serial.println("Error on HTTP request");
    }  
  }
  else{
    Serial.println("Connection lost");
    
  }
  delay(10000);

}
