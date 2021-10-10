#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "Hadid.Techno"        
#define _PASSWORD "0r1g4m1m4s3t3r"    
#define PROJECT_ID "smarthome-a9ded"

Firebase firebase(PROJECT_ID); 

int saklar1, saklar2, saklar3, saklar4;
int led[] = {14,12,13,15};

void setup() {
  Serial.begin(115200);
  for(int i=0; i <4; i++){
    pinMode(led[i], OUTPUT);
  }
  WiFi.mode(WIFI_STA);
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
}

void loop() {
  String data = firebase.getString("saklar");  // Get data from database.
  Serial.println(""+data);

  // Deserialize the data.
  // Consider using the Arduino Json assistant- https://arduinojson.org/v6/assistant/
  const size_t capacity = JSON_OBJECT_SIZE(5) + 60;
  DynamicJsonDocument doc(capacity);

  deserializeJson(doc, data);

  String Device1 = doc["saklar1"];
  String Device2 = doc["saklar2"];
  String Device3 = doc["saklar3"];
  String Device4 = doc["saklar4"];

  // Print data
  Serial.println("Device 1: "+Device1);
  Serial.println("Device 2: "+Device2);
  Serial.println("Device 3: "+Device3);
  Serial.println("Device 4: "+Device4);
  Serial.println("");

  String status_list[4] = {Device1, Device2, Device3, Device4};

  for (int i=0;i<4;i++) {
    if (status_list[i] == "ON"){
      digitalWrite(led[i], HIGH);
      Serial.println("on"+i);
    }
    else{
      digitalWrite(led[i], LOW);
      Serial.println("off"+i);
    }
  }
  
}
