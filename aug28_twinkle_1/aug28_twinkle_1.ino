//Random Flash animation for Neopixel Ring Bangle Bracelet
//by Dano Wall and Becky Stern for Adafruit Industries
//based on the Sparkle Skirt, minus the accelerometer
#include <Adafruit_NeoPixel.h>

#define PIN 5
#define PIN 6


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_a = Adafruit_NeoPixel(25, 5);
Adafruit_NeoPixel strip_b = Adafruit_NeoPixel(25, 6);

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  6;      // the number of the LED pin



// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  strip_a.begin();
  strip_b.begin();
  strip_a.setBrightness(25);
  strip_b.setBrightness(75);
  strip_a.show(); 
  strip_b.show(); // Initialize all pixels to 'off'
  
//  // initialize the LED pin as an output:
//  pinMode(ledPin, OUTPUT);      
//  // initialize the pushbutton pin as an input:
//  pinMode(buttonPin, INPUT);     
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    firefly1(strip_a.Color(255, 255, 0), 100); 
    firefly2(strip_b.Color(255, 0, 0), 0); 
  } 
  else {
    // turn LED off:
    firefly1(strip_a.Color(0, 0, 0), 100); 
    firefly2(strip_b.Color(0, 0, 0), 0); 
  }
}

void firefly1(uint32_t c, uint8_t wait){
      for(uint32_t i=0; i<strip_a.numPixels(); i++){
    strip_a.setPixelColor(i, c);
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /= 5;
      int g = 255 * (x+1); g /= 5;
      int b = 0 * (x+1); b /= 5;
      
      strip_a.setPixelColor(i, strip_a.Color(r, g, b));
      strip_a.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 5;
      int g = 255 * x; g /= 5;
      int b = 0 * x; b /= 5;
      
      strip_a.setPixelColor(i, strip_a.Color(r, g, b));
      strip_a.show();
      delay(wait);
    }
  }
 }


void firefly2(uint32_t c, uint8_t wait){
      for(uint32_t i=0; i<strip_b.numPixels(); i++){
    strip_b.setPixelColor(i, c);
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /= 5;
      int g = 255 * (x+1); g /= 5;
      int b = 0 * (x+1); b /= 5;
      
      strip_b.setPixelColor(i, strip_b.Color(r, g, b));
      strip_b.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 5;
      int g = 255 * x; g /= 5;
      int b = 0 * x; b /= 5;
      
      strip_b.setPixelColor(i, strip_b.Color(r, g, b));
      strip_b.show();
      delay(wait);
    }
  }
 }

  // LEDs will be off when done (they are faded to 0)



