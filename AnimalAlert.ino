#include "Modulino.h"

ModulinoDistance distance;
ModulinoBuzzer buzzer;
ModulinoPixels leds;

ModulinoColor blue(0, 0, 255); // RGB: Blue

void setup() {
  Modulino.begin();
  distance.begin();
  buzzer.begin();
  leds.begin();  // Initialize the LEDs
}

void loop() {
  if (distance.available()) {
    int measure = distance.get(); 
    buzzer.tone(1000, 100);

    // Light up first 8 LEDs with blue color
    for (int i = 0; i < 8; i++) {
      leds.set(i, blue);
    }
    leds.show();
    delay(200);

    // Turn off LEDs after a short delay
    leds.clear();
    leds.show();
    delay(100);
  }
}
