const int jmlled = 5;
int led1[]= {13,12,11,10,9};
int led2[]= {9,10,11,12,13};
int i;

void setup() {
  for (i=0; i<jmlled; i++){
    pinMode (led1[i], OUTPUT);
    pinMode (led2[i], OUTPUT);
    }
}

void loop() {
  jalan();
  mati();
  nyala();
  mati();

    
  
}
void jalan() {
   for (i=0; i<jmlled; i++){
    digitalWrite (led1[i], HIGH);
    delay(200);
    digitalWrite (led1[i], LOW);
    digitalWrite (led2[i], HIGH);
    delay(200);
    digitalWrite (led2[i], LOW);
  }
  
  
}

void nyala() {
   for (i=0; i<jmlled; i++){
     digitalWrite (led1[i], HIGH);
     delay (500);
     }
 

}

void mati() {
  for (i=0; i<jmlled; i++){
    digitalWrite (led1[i], LOW);
    digitalWrite (led2[i], LOW);
  }
  

  
}
