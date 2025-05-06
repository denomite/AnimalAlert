#include "Modulino.h"

ModulinoDistance distance;
ModulinoBuzzer buzzer;

void setup() {
  Modulino.begin();
  distance.begin();
  buzzer.begin();
}

void loop() {
  if (distance.available()) {
    int measure = distance.get(); 
    buzzer.tone(1000, 100);
    delay(10); 
  }
}