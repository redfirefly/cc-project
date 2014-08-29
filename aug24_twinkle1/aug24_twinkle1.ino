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

// Here is where you can put in your favorite colors that will appear!
// just add new {nnn, nnn, nnn}, lines. They will be picked out randomly
//                          R   G   B
uint8_t myColors[][3] = {{255, 255, 0},   // green yellow
                         {255, 255, 0},   // yellow 
                         {255, 255, 0},   // light yellow
                          };

//uint8_t myColors[][3] = {{153, 255, 51},   // green yellow
//                         {200, 200, 20},   // yellow 
//                         {255, 255, 153},   // light yellow
//                          };
                               
// don't edit the line below
#define FAVCOLORS sizeof(myColors) / 3

void setup() {
  strip.begin();
  strip.setBrightness(20);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
flashRandom(100, 1);  // first number is 'wait' delay, shorter num == shorter twinkle
//flashRandom(200, 3);  // second number is how many neopixels to simultaneously light up
//flashRandom(250, 2);
}

void flashRandom(int wait, uint8_t howmany) {
 
  for(uint16_t i=0; i<howmany; i++) {
    // pick a random favorite color!
    int c = random(FAVCOLORS);
    int red = myColors[c][0];
    int green = myColors[c][1];
    int blue = myColors[c][2]; 
 
    // get a random pixel from the list
//    int j = random(strip.numPixels());
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /= 5;
      int g = 255 * (x+1); g /= 5;
      int b = 0 * (x+1); b /= 5;
      
//      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 5;
      int g = 255 * x; g /= 5;
      int b = 0 * x; b /= 5;
      
//      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
  }
  // LEDs will be off when done (they are faded to 0)
}

