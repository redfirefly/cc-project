// This code combines the pixel fade in/ out with animation sequence.
// Using the Fn declarion, you can add the numbers on the back of the LED to an animation sequence. 
//next step: add variation in fading and brightness per firefly

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
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);

int f1[] = {3,1,2,0,0,3,1,2}; //add numbers from back of LEDs in animation order

int f2[] = {0,1,3,1,1,2,2,0}; //add numbers from back of LEDs in animation order

//int f3[]={28,29,30,31,32); //add numbers from back of LEDs in animation order
//
//int f4[]={33,34,35,36,37,38); //add numbers from back of LEDs in animation order
//
//
//int f5[]={n,n,n,n,n,n); //add numbers from back of LEDs in animation order


// constants won't change. They're used here to 
// set pin numbers:
//const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  6;      // the number of the LED pin

// variables will change:
//int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  strip.begin();
  strip.setBrightness(25);
  strip.show(); // Initialize all pixels to 'off'
  
  // initialize the LED pin as an output:
//  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
//  pinMode(buttonPin, INPUT);     
}

void loop() {
  // read the state of the pushbutton value:
//  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
//  if (buttonState == HIGH) {     
    // turn LED on:    
    firefly(strip.Color(255, 255, 0), 100); 
  } 
//  else {
//    // turn LED off:
//    firefly(strip.Color(0, 0, 0), 100); 
//  }
//}

void firefly(uint32_t c, uint8_t wait){
//      for(uint32_t i=sine[i]; i<strip.numPixels(); i--){
  for(int i=0; i<50; i++){
    strip.setPixelColor(f1[i], c);
    strip.setPixelColor(f2[i], c);
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /= 5;
      int g = 255 * (x+1); g /= 5;
      int b = 0 * (x+1); b /= 5;
      
      strip.setPixelColor(f1[i], strip.Color(r, g, b));
      strip.setPixelColor(f2[i], strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 5;
      int g = 255 * x; g /= 5;
      int b = 0 * x; b /= 5;
      
      strip.setPixelColor(f1[i], strip.Color(r, g, b));
      strip.setPixelColor(f2[i], strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
  }
 }

  // LEDs will be off when done (they are faded to 0)



