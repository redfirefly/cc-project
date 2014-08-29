//Random Flash animation for Neopixel Ring Bangle Bracelet
//by Dano Wall and Becky Stern for Adafruit Industries
//based on the Sparkle Skirt, minus the accelerometer
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
  strip.setBrightness(25);
  strip.show(); // Initialize all pixels to 'off'
}
  
void loop(){
      for(uint32_t i=0; i<strip.numPixels(); i++){
      delay(2000);
    strip.setPixelColor(i, 255, 255, 0);
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /= 5;
      int g = 255 * (x+1); g /= 5;
      int b = 0 * (x+1); b /= 5;
      
      strip.setPixelColor(i, strip.Color(r, g, b));
      strip.show();
      delay(250);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 5;
      int g = 255 * x; g /= 5;
      int b = 0 * x; b /= 5;
      
      strip.setPixelColor(i, strip.Color(r, g, b));
      strip.show();
      delay(250);
    }
  }
 }
// 
// void loop2(){
//      for(uint16_t i=0; i<strip.numPixels(); i++){
//      delay(1000);
//    strip.setPixelColor(i, 0, 200, 0);
//    
//    // now we will 'fade' it in 5 steps
//    for (int x=0; x < 5; x++) {
//      int r = 0 * (x+1); r /= 5;
//      int g = 200 * (x+1); g /= 5;
//      int b = 0 * (x+1); b /= 5;
//      
//      strip.setPixelColor(i, strip.Color(r, g, b));
//      strip.show();
//      delay(250);
//    }
//    // & fade out in 5 steps
//    for (int x=5; x >= 0; x--) {
//      int r = 0 * x; r /= 5;
//      int g = 200 * x; g /= 5;
//      int b = 0 * x; b /= 5;
//      
//      strip.setPixelColor(i, strip.Color(r, g, b));
//      strip.show();
//      delay(250);
//    }
//  }
// }
  // LEDs will be off when done (they are faded to 0)



