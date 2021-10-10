#include <ESP8266WiFi.h>
#define mtr1 D2
#define mtr2 D3
#define mtr3 D4
#define mtr4 D5
#define echo D6
#define trig D7
#define led D8

void setup()
{
  pinMode(mtr1, OUTPUT);
  pinMode(mtr2, OUTPUT);
  pinMode(mtr3, OUTPUT);
  pinMode(mtr4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
}

void loop()
{
  work();

}

void work(){
  long waktu, jarak;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  waktu = pulseIn(echo, HIGH);
  jarak = (waktu/2)/29.1;
  Serial.println(jarak);
  
  if(jarak <= 10){
    digitalWrite(mtr1, HIGH);
    digitalWrite(mtr2, LOW);
    digitalWrite(mtr3, LOW);
    digitalWrite(mtr4, LOW);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
     digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }else {
    digitalWrite(mtr1, LOW);
    digitalWrite(mtr2, HIGH);
    digitalWrite(mtr3, LOW);
    digitalWrite(mtr4, HIGH);
    digitalWrite(led, LOW);
  }


}
