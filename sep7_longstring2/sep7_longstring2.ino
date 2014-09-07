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
Adafruit_NeoPixel strip = Adafruit_NeoPixel(45, PIN, NEO_GRB + NEO_KHZ800);

int f1[] = {4, 11, 23, 43}; //add numbers from back of LEDs in animation order

int f2[] = {32,14,13,10,12,6}; //add numbers from back of LEDs in animation order

int f3[]= {42,41,40,39,38,37}; //add numbers from back of LEDs in animation order
//
int f4[]= {2,9,28,17,18,19}; //add numbers from back of LEDs in animation order
//
//
int f5[]= {24,27,5,31,33}; // vertical strip in middle

int f6[] = {0, 37, 26, 30};


// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int miniledPin = 13;

int current; //Current state of the button (LOW is pressed b/c i'm using the pullup resistors
int count;   // How long the button was held (secs)
byte previous = HIGH;
unsigned long firstTime;   // how long since the button was first pressed 


void setup() {
  strip.begin();
  strip.setBrightness(25);
  strip.show(); // Initialize all pixels to 'off'
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);    
  pinMode(miniledPin, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);    
 // initialize serial communication:
  Serial.begin(9600); 
}

void loop() {
 
 {
  current = digitalRead(buttonPin);
  if (current == LOW && previous == HIGH && millis() - firstTime > 200){
    firstTime = millis();    // if the buttons becomes press remember the time 
  }

  if (current == LOW && ((millis() - firstTime) % 1000) < 20 && millis() - firstTime > 500){
    ledblink(1, 50, miniledPin);// Each second the button is held blink the indicator led and
    count++;                // and add 1 to the counter
    Serial.println(count);
  }
  if (current == HIGH && previous == LOW && count >=2 && count < 6){
    firefly(strip.Color(255, 255, 0), 100);
    Serial.println("more fireflies"); // When the button is released if the counter is between the
  }                          // two numbers (2-6 blinks or secs) run the program

  if (current == HIGH && previous == LOW && count >=0 && count < 2){
    fireflies(strip.Color(255, 255, 0), 100);
    Serial.println("few fireflies"); //This is where you would put you differnt functions
  }                                // with diffent time parameters

  if (current == HIGH){ // reset the counter if the button is not pressed
    count = 0;
  }

  previous = current;
  
 }
 
}  


void ledblink(int times, int lengthms, int pinnum){
  for (int x=0; x<times;x++){
    digitalWrite(pinnum, HIGH);
    delay (lengthms);
    digitalWrite(pinnum, LOW);
    delay(lengthms);
  }
}
  

void firefly(uint32_t c, uint8_t wait){
//      for(uint32_t i=sine[i]; i<strip.numPixels(); i--){
  for(int i=0; i<4; i++){
    strip.setBrightness(5);
    strip.setPixelColor(f6[i], c);
    strip.setPixelColor(f1[i], c);
//    strip.setPixelColor(f3[i], c);
    //strip.setPixelColor(f4[i], c);
//    strip.setPixelColor(f5[i], c);
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /= 6;
      int g = 255 * (x+1); g /= 6;
      int b = 0 * (x+1); b /= 6;
      
      strip.setPixelColor(f6[i], strip.Color(r, g, b));
      strip.setPixelColor(f1[i], strip.Color(r, g, b));
//      strip.setPixelColor(f3[i], strip.Color(r, g, b));
    //  strip.setPixelColor(f4[i], strip.Color(r, g, b));
//      strip.setPixelColor(f5[i], strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 6;
      int g = 255 * x; g /= 6;
      int b = 0 * x; b /= 6;
      
      strip.setPixelColor(f6[i], strip.Color(r, g, b));
      strip.setPixelColor(f1[i], strip.Color(r, g, b));
//      strip.setPixelColor(f3[i], strip.Color(r, g, b));
   //   strip.setPixelColor(f4[i], strip.Color(r, g, b));
//      strip.setPixelColor(f5[i], strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
  }
 }

  // LEDs will be off when done (they are faded to 0)

void fireflies(uint32_t c, uint8_t wait){
//      for(uint32_t i=sine[i]; i<strip.numPixels(); i--){
  for(int i=0; i<6 ; i++){
    strip.setBrightness(25);
    strip.setPixelColor(f2[i], c);
    strip.setPixelColor(f3[i], c);
    strip.setPixelColor(f3[i], c);
    strip.setPixelColor(f5[i], c);
//    strip.setPixelColor(f6[i], c);
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = 255 * (x+1); r /=5;
      int g = 255 * (x+1); g /=5;
      int b = 0 * (x+1); b /= 5;
      
      strip.setPixelColor(f2[i], strip.Color(r, g, b));
      strip.setPixelColor(f3[i], strip.Color(r, g, b));
      strip.setPixelColor(f4[i], strip.Color(r, g, b));
      strip.setPixelColor(f5[i], strip.Color(r, g, b));
//      strip.setPixelColor(f6[i], strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = 255 * x; r /= 5;
      int g = 255 * x; g /= 5;
      int b = 0 * x; b /= 5;
      
      strip.setPixelColor(f2[i], strip.Color(r, g, b));
      strip.setPixelColor(f3[i], strip.Color(r, g, b));
      strip.setPixelColor(f4 [i], strip.Color(r, g, b));
      strip.setPixelColor(f5[i], strip.Color(r, g, b));
//      strip.setPixelColor(f6[i], strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
  }
 }

  // LEDs will be off when done (they are faded to 0)
