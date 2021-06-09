#include <TFT_HX8357_Due.h>
#include "color.h"
#include "geometry.h"
#include "math.h"

#define K1 10
#define K2 11
#define K3 12
#define K4 13

#define FOV 60
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define HALF_SCREEN_WIDTH 240
#define HALF_SCREEN_HEIGHT 160

TFT_HX8357_Due tft = TFT_HX8357_Due();

Matrix4f m_world;

void mode_ui(const uint16_t color)
{
  tft.setCursor(0, 2);
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.println("Author: @cyq");
}

void draw_vertex(int vertex_cnts, Vector2f *projected, const uint16_t color)
{
  for (int i = 0; i < vertex_cnts; i++)
  {
    tft.drawPixel(projected[i].x, projected[i].y, color);
  }
}

void draw_triangles(int triangle_cnts, Vector2f *projected, const Vector3i *indices, const uint16_t color)
{
  for (int i = 0; i < triangle_cnts; i++)
  {
    Vector3i index = indices[i];
    Vector2f v0 = projected[index.x];
    Vector2f v1 = projected[index.y];
    Vector2f v2 = projected[index.z];
    if (is_visible(v0, v1, v2))
    {
      tft.drawTriangle(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y, color);
    }
  }
}

void setup()
{
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(1);

  tft.fillScreen(BLACK);
  mode_ui(WHITE);
  m_world = mMultiply(mScale(0.3), m_world);
  m_world = mMultiply(mRotateY(45), m_world);
}

void loop(void)
{
  int start = millis();
  bunny obj;

  // for future, z-buffer
  for (int i = 0; i < obj.vertex_counts; i++)
  {
    // no camera
    // project to screen space directly
    Vector3f v = m_mul_v(m_world, obj.vertex_pos[i]);
    obj.projected_vertex[i].x = (FOV * v.x) / (FOV + v.z) + HALF_SCREEN_WIDTH;
    obj.projected_vertex[i].y = (FOV * v.y) / (FOV + v.z) + HALF_SCREEN_HEIGHT;
  }

  tft.fillScreen(BLACK);
  draw_triangles(obj.triangle_counts, obj.projected_vertex, obj.indices, GREEN);
  // clear frame
  // draw_triangles(obj.triangle_counts, obj.projected_vertex, obj.indices, TFT_WHITE);

  int end = millis();
  Serial.println(1000 / (end - start));
}
