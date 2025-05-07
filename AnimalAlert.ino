#include "Modulino.h"

ModulinoDistance distance;
ModulinoBuzzer buzzer;
ModulinoPixels leds;

ModulinoColor red(255, 0, 0);
ModulinoColor yellow(255, 255, 0);
ModulinoColor green(0, 255, 0);

void setup() {
  Modulino.begin();
  distance.begin();
  buzzer.begin();
  leds.begin();
}

void loop() {
  if (distance.available()) {
    int measure = distance.get(); 
    buzzer.tone(1000, 100);

    ModulinoColor color = ModulinoColor(0, 0, 0);

    if (measure < 100) {
      color = red;
    } else if (measure < 300) {
      color = yellow;
    } else {
      color = green;
    }

    // Light up all 8 LEDs with the selected color
    for (int i = 0; i < 8; i++) {
      leds.set(i, color);
    }
    leds.show();
    delay(200);

    leds.clear();
    leds.show();
    delay(100);
  }
}
