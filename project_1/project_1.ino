//inisialisasi
#define iniled1 D4

void setup() {
  pinMode(iniled1, OUTPUT);//variable iniled1

}

void loop() {
   digitalWrite(iniled1, HIGH);//nyala
   delay(1000);
   digitalWrite(iniled1, LOW);//mati
   delay(1000);
   digitalWrite(iniled1, HIGH);//nyala
   delay(100);
   digitalWrite(iniled1, LOW);//mati
   delay(100);
   digitalWrite(iniled1, HIGH);//nyala
   delay(1000);
   digitalWrite(iniled1, LOW);//mati
   delay(1000);
   
}
