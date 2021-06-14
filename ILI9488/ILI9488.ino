#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>

#define TFT_CS 9
#define TFT_DC 7
#define TFT_LED 8
#define TFT_RST 6

ILI9488 display = ILI9488(TFT_CS, TFT_DC, TFT_RST);

//
// The easiest raytracer in the world
//

#define RGBTO565(_r, _g, _b) ((((_r)&B11111000) << 8) | (((_g)&B11111100) << 3) | ((_b) >> 3))
#include "raytracer.h"

void setup()
{
  //  Serial.begin(115200);
  Serial.begin(9600);
  display.begin();
  display.setTextColor(ILI9488_WHITE, ILI9488_BLACK);
  display.setTextSize(1);

  display.setRotation(1);
  display.fillScreen(0);

  unsigned long t = millis();
  doRaytrace(8, 480, 320, 1); // full 320x240 1 sample
                              //  doRaytrace(1,320,240,4); // fast preview
                              //  doRaytrace(1,320,240,2); // slower preview
                              //  doRaytrace(1,160,120,2); // quarter of the screen
                              //  doRaytrace(8);  // very high quality 320x240 antialiased, 8 samples
  Serial.println(F("Done!"));
  Serial.print(F("Time = "));
  Serial.print((millis() - t) / 1000);
  Serial.println(F(" seconds"));
}

void loop(void)
{
}