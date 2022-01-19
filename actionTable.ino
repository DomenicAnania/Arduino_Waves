void actionTable() {
  switch(action) {
    
    case 0:
    //place the adafruit first example procedure here 
    //red lights
    colorWipe(neoring.Color(255, 0, 0), 50); // Red

  
    break;

    case 1:
    //place the second procedure example here
    //green lights
    colorWipe(neoring.Color(101, 67, 33), 50); // Brown
    
    break;

    case 2: 
    //blue lights
    colorWipe(neoring.Color(40,160,200), 50); // Blue



    break;

    case 3:
    //how about theatre chase in white? 
    theaterChase(neoring.Color(127, 127, 127), 50); // White
    
    break;

    case 4:
    //theatre chase in red
    theaterChase(neoring.Color(127, 0, 0), 50); // Red

   
    break;

    case 5:
    // theatre chase in Blue
    theaterChase(neoring.Color(40,160,200), 50); // Blue
    

    break;

    case 6:
    //how about a theatre chase in green?
    theaterChase(neoring.Color(0, 127, 0), 50); // Blue
    

    break;

    case 7:
    //how about a theatre chase in 3 numbers you just made up to see what colour comes out?
    theaterChase(neoring.Color(67, 120, 32), 50); // Random Colour
  

    break;
        
    case 8:
    //Let's try a rainbow effect!
    rainbow(20);
    

    break;

    case 9:
    //let's try rainbow cycle
    rainbowCycle(20);
    

    break;

    case 10:
    //what is our last example procedure to try out
    theaterChaseRainbow(50);

    
    break;
    
  }
}

//Below this code you need to add all of void functions that will run your action table code

//This is the first one, colorWipe, a few things need to happen when you hack found code
//1) check the words and make sure their yours and not from the coder you stole from.
//2) if there is a for loop use our term ringTotal instead


// Fill the dots one after the other with a color
void colorWipe(uint32_t c,uint8_t wait) {
  //for loop is missing how many leds we have to change, either put the number or the word you made
  //to represent that number - ringTotal
  for(uint16_t i=0; i< neoring.numPixels(); i++) {
    //Use your word to represent the neo pixel ring from the orange text Adafruit_NeoPixel...
    neoring.setPixelColor(i, c);
    neoring.show();
    delay(100);
  }
}
 
//Now paste in the rainbow function, dont forget to make your 2 types of changes like above
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=15; j<51; j++) {
    for(j=15; j>15  ; j++){
    for(i=0; i<neoring.numPixels(); i++) {
      neoring.setPixelColor(i, Wheel((i+j) & 120));
    }
    neoring.show();
    delay(wait);
    }
  }
}
//Wait does rainbow have a new function to add?
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< neoring.numPixels(); i++) {
      neoring.setPixelColor(i, Wheel(((i * 256 / neoring.numPixels()) + j) & 255));
    }
    neoring.show();
    delay(wait);
  }
}
//Now paste in rainbowCycle & make the 2 types of changes


//Now paste theatre chase
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < neoring.numPixels(); i=i+3) {
        neoring.setPixelColor(i+q, c);    //turn every third pixel on
      }
      neoring.show();

      delay(wait);

      for (uint16_t i=0; i < neoring.numPixels(); i=i+3) {
        neoring.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
//Now paste theatre chase rainbow
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < (0,0,255); j++) {     // cycle all 256 colors in the wheel
//    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < neoring.numPixels(); i=i++) {
        neoring.setPixelColor(i++, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      neoring.show();

      delay(wait);

      for (uint16_t i=0; i < neoring.numPixels(); i=i++) {
        neoring.setPixelColor(i++, 0);        //turn every third pixel off
      }
    }
  }
