#include <FastLED.h>

#define LED_PIN     5
#define COLOR_ORDER RGB
#define CHIPSET     WS2811
#define NUM_LEDS    120

#define BRIGHTNESS  200
#define FRAMES_PER_SECOND 120

const int matrix[12][10] = {
      { 76, 75, 68, 67, 60, 59, 52, 51, 44, 43 },
      { 77, 74, 69, 66, 61, 58, 53, 50, 45, 42 },
      { 78, 73, 70, 65, 62, 57, 54, 49, 46, 41 },
      { 79, 72, 71, 64, 63, 56, 55, 48, 47, 40 },
      { 80, 87, 88, 95, 96, 23, 24, 31, 32, 39 },
      { 81, 86, 89, 94, 97, 22, 25, 30, 33, 38 },
      { 82, 85, 90, 93, 98, 21, 26, 29, 34, 37 },
      { 83, 84, 91, 92, 99, 20, 27, 28, 35, 36 },
      { 116, 115, 108, 107, 100, 19, 12, 11, 4, 3 },
      { 117, 114, 109, 106, 101, 18, 13, 10, 5, 2 },
      { 118, 113, 110, 105, 102, 17, 14, 9, 6, 1 },
      { 119, 112, 111, 104, 103, 16, 15, 8, 7, 0 }
};


CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
  pixelfur(1);
  delay(6000);
  pixelfur(2);
  delay(100);
  pixelfur(3);
  delay(500);
}


void pixelfur(int z)
{
  const CRGB er = CRGB(132,36,13);
  const CRGB bk = CRGB(100,100,100);
  const CRGB ee = CRGB(226,226,28);
  const CRGB bg = CRGB(0,0,0);
  const CRGB rr = CRGB(250,0,0);
  const CRGB colormap[12][10] = {
      { bg, bg, er, bg, bg, bg, bg, er, bg, bg },
      { bg, er, bg, er, bg, bg, er, bg, er, bg },
      { bg, er, bg, er, bg, bg, er, bg, er, bg },
      { er, bg, bg, bg, bg, bg, bg, bg, bg, er },
      { bg, bg, ee, bg, bg, bg, bg, ee, bg, bg },
      { bg, bg, ee, bg, bg, bg, bg, ee, bg, bg },
      { bg, bg, bg, bg, bg, bg, bg, bg, bg, bg },
      { bg, bg, bg, bg, bg, bg, bg, bg, bg, bg },
      { bg, bk, bg, bg, bg, bg, bg, bg, bk, bg },
      { bg, bk, bg, bg, bk, bk, bg, bg, bk, bg },
      { bg, bg, bk, bk, bg, bg, bk, bk, bg, bg },
      { bg, bg, bg, bg, bg, bg, bg, bg, bg, bg }
  };

  switch(z){
  case 1:
    for(int i = 0; i < 12; i++){
      for(int k = 0; k < 10; k++){
        leds[matrix[i][k]] = colormap[i][k];
      }
    }
    
    FastLED.show(); // display this frame
    FastLED.delay(1000 / FRAMES_PER_SECOND);
  break;
  case 2:
    leds[matrix[4][2]] = leds[matrix[4][7]] =  bg;
    leds[matrix[10][4]] = leds[matrix[10][5]] = rr;
    FastLED.show(); // display this frame
    FastLED.delay(1000 / FRAMES_PER_SECOND);
  break;
  case 3:
    leds[matrix[5][2]] = leds[matrix[5][7]] = bg;
    leds[matrix[11][4]] = leds[matrix[11][5]] = rr;
    FastLED.show(); // display this frame
    FastLED.delay(1000 / FRAMES_PER_SECOND);
  break;
  };
 
}


