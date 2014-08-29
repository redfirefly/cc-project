#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
    randomSeed(analogRead(0));
}

void loop() {

 int rand = random(200); // max amt of time between brightness changes
 int numLEDs = 18; // 18 for Canvas


 strip.setPixelColor(random(0,numLEDs),strip.Color(255, 255, 255)); // 255 is brightest
 strip.show();
 delay(rand);
 
 strip.setPixelColor(random(0,numLEDs),strip.Color(127, 127, 127)); 
 strip.show();
 delay(rand);
 
 strip.setPixelColor(random(0,numLEDs),strip.Color(50, 50, 50));
 strip.show();
 delay(rand);
 
 strip.setPixelColor(random(0,numLEDs),strip.Color(0, 0, 0)); //  0 is off
 strip.show();
 delay(rand);
}

