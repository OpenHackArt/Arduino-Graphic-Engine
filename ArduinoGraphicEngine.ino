#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#include "color.h"
#include "geometry.h"
#include "data_structure.h"
#include "math.h"

#define TFT_CS 7
#define TFT_DC 9
#define TFT_LED 8
#define TFT_RST 10

#define FOV 60
#define TICK_PER_FRAME 17 // 60 fps
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480
#define HALF_SCREEN_WIDTH 160
#define HALF_SCREEN_HEIGHT 240

#define MAX_VERTEX 200

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

float ticks = 0;
unsigned int loops = 0;

int total_vertex = 0;
Matrix4f m_world;
float projected_vertex[MAX_VERTEX][2]; // (x, y) screen space
unsigned short render_mode = 0;        // 0 - orthogonal | 1 - perspective

void mode_ui(const uint16_t color)
{
  tft.setCursor(0, 2);
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.println("Author: @cyq");
  if (render_mode == 0)
  {
    tft.println("Mode: Orthogonal");
  }
  else
  {
    tft.println("Mode: Perspective");
  }
  tft.print("Max vertex: ");
  tft.println(MAX_VERTEX);
}

void draw_vertex(const uint16_t color)
{
  for (int i = 0; i < total_vertex; i++)
  {
    tft.drawPixel(projected_vertex[i][0], projected_vertex[i][1], color);
  }
}

void setup()
{
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(0);

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9488_RDMODE);
  Serial.print("Display Power Mode: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9488_RDMADCTL);
  Serial.print("MADCTL Mode: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9488_RDPIXFMT);
  Serial.print("Pixel Format: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9488_RDIMGFMT);
  Serial.print("Image Format: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9488_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x");
  Serial.println(x, HEX);

  tft.fillScreen(WHITE);
  mode_ui(BLACK);
  ticks = millis();
}

void loop(void)
{
  while (millis() > ticks)
  {
    // m_world = mMultiply(mRotateX(10), m_world);
    // m_world = mMultiply(mScale(10), m_world);
    cube obj;
    total_vertex += obj.vertex_counts;
    Vector3f p;
    // for future, z-buffer
    for (int i = 0; i < obj.vertex_counts; i++)
    {

      // no camera
      // project to screen space directly
      Vector3f v = m_mul_v(m_world, obj.vertex_pos[i]);
      projected_vertex[i][0] = (FOV * v.x) / (FOV * v.z) + HALF_SCREEN_WIDTH;
      projected_vertex[i][1] = (FOV * v.y) / (FOV * v.z) + HALF_SCREEN_HEIGHT;
    }

    ticks += TICK_PER_FRAME;
  }

  draw_vertex(BLACK);
}
