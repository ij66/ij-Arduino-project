
#define led D2
#include <Servo.h>
Servo servoku;
#define btn D4
int nilai;

void setup() {
  Serial.begin(115200);
  pinMode (led, OUTPUT);
  pinMode (btn, INPUT);
  servoku.attach(D3);

}

void loop() {
  nilai = digitalRead(btn);
  Serial.println(nilai);
  if(nilai == 1){
    servoku.write(180);
    delay(1000);
    }
    else{
      servoku.write(0);
      delay(1000);
    }
  
}
