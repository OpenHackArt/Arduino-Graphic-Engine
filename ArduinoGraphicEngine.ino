#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#include "color.h"
#include "geometry.h"
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

Matrix4f m_world;
unsigned short render_mode = 1; // 0 - orthogonal | 1 - perspective

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

void draw_vertex(int vertex_cnts, Vector2f *projected, const uint16_t color)
{
  for (int i = 0; i < vertex_cnts; i++)
  {
    tft.drawPixel(projected[i].x, projected[i].y, color);
  }
}

void draw_triangles(int vertex_cnts, Vector2f *projected, const Vector3i *tris, const uint16_t color)
{
  for (int i = 0; i < vertex_cnts; i++)
  {
    // draw triangle edges - 0 -> 1 -> 2 -> 0
    tft.drawLine(projected[tris[i].x].x, projected[tris[i].x].y, projected[tris[i].y].x, projected[tris[i].y].y, color);
    tft.drawLine(projected[tris[i].y].x, projected[tris[i].y].y, projected[tris[i].z].x, projected[tris[i].z].y, color);
    tft.drawLine(projected[tris[i].z].x, projected[tris[i].z].y, projected[tris[i].x].x, projected[tris[i].x].y, color);
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
  m_world = mMultiply(mScale(30), m_world);
}

void loop(void)
{
  cube obj;
  while (millis() > ticks)
  {
    // m_world = mMultiply(mRotateX(10), m_world);

    // for future, z-buffer
    for (int i = 0; i < obj.vertex_counts; i++)
    {
      // no camera
      // project to screen space directly
      Vector3f v = m_mul_v(m_world, obj.vertex_pos[i]);
      obj.projected_vertex[i].x = (FOV * v.x) / (FOV + v.z) + HALF_SCREEN_WIDTH;
      obj.projected_vertex[i].y = (FOV * v.y) / (FOV + v.z) + HALF_SCREEN_HEIGHT;
    }

    ticks += TICK_PER_FRAME;
  }

  draw_vertex(obj.vertex_counts, obj.projected_vertex, BLACK);
  draw_triangles(obj.vertex_counts, obj.projected_vertex, obj.triangles, RED);
}
