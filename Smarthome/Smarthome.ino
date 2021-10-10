#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "smarthome-a9ded-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Q7hU7heTk9bFV7Zv1I0BvKTtzkAnxs1kKZCKcYiu"
#define WIFI_SSID "realmi 5i"
#define WIFI_PASSWORD "12345678"

int saklar1, saklar2, saklar3, saklar4;
int led[] = {14,12,13,15};

void setup() {
  
  Serial.begin(115200);
  for(int i=0; i <4; i++){
    pinMode(led[i], OUTPUT);
  }

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
saklar1=Firebase.getString("saklar/saklar1").toInt();
saklar2=Firebase.getString("saklar/saklar2").toInt();
saklar3=Firebase.getString("saklar/saklar3").toInt();
saklar4=Firebase.getString("saklar/saklar4").toInt();

if(saklar1==1){
  digitalWrite(led[0], HIGH); 
  Serial.println("Saklar 1 ON");
}
if(saklar1==0){
  digitalWrite(led[0], LOW);
  Serial.println("Saklar 2 OFF");
}
if(saklar2==1){
  digitalWrite(led[1], HIGH);
  Serial.println("Saklar 2 ON");
}
if(saklar2==0){
  digitalWrite(led[1], LOW);
  Serial.println("Saklar 2 OFF");
}
if(saklar3==1){
  digitalWrite(led[2], HIGH); 
  Serial.println("Saklar 3 ON");
}
if(saklar3==0){
  digitalWrite(led[2], LOW); 
  Serial.println("Saklar 3 OFF");
}
if(saklar4==1){
  digitalWrite(led[3], HIGH);
  Serial.println("Saklar 4 ON"); 
}
if(saklar4==0){
  digitalWrite(led[3], LOW);
  Serial.println("Saklar 4 OFF"); 
}
}
