/* Strandtest_behaviour - converting arduino sample code into behavour table template
 *  This code will take the example/adrafruit neopixel/strandtest code and convert it into
 *  a creative coding template. this code is an exercise to learn how the template works 
 *  before adding creative code.
 */
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//What PWM pin do you want to use? Here we don't need the ";" at the end because of #define
#define PIN 3

//type how many leds you have on you neopixel ring part here
int ringTotal = 9;

//this is the varable that will control what behaviour happens when. In this code, it is just going
//to cycle through them, so where on the table do you want to start?
int action = 0;


//create an array of numbers that will pick the order of behaviours rather than just going trough the 
//code one after another - use numbers from your switch case 0 to 8 and use a comma between each 
//number and create a performance with the cases for as long as you like
int lightShow[] = {
8
//2,1,5,2,1,2
};  //an array of cases to be called up in an order decided by myself on a piece of paper

//this value represents how long the array is or how many light show acts we have in the light performance
//the number should match the array number
int lightShowLength = 1;
//this value tracks where we are in the light show to display it so it starts at zero, the begining
//number as an array
int lightShowCounter = 0;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

//What do you want to call your neo pixel ring, put your word before the equal sign
//call it ring?
//Also in the blank spot put the number of LEDs are on your ring
Adafruit_NeoPixel neoring = Adafruit_NeoPixel( ringTotal, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...turn unplug the arduino.

void setup() {
  Serial.begin(9600);
  //Note that this code defines our ring and not a strip, need to add your word for your neopixel
  //ring before the dot on these two words
  neoring.begin();
  neoring.show(); // Initialize all pixels to 'off'
}

void loop() {
  action = lightShow[lightShowCounter];
  actionTable();
  
  
  delay(50);

  if (lightShowCounter < lightShowLength) {
    //when light show counter is less then the length this line of code needs to move to the next case
    //what variable do we need to add before the "++"
    lightShowCounter++;
  }
  

  action++;
  if (action > 0) {
    action = 0;
  }
}  
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return neoring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return neoring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return neoring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
