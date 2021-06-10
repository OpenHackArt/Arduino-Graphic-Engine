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
#define MAX_VERTEX 2000

Vector2f current_frame_vertex[MAX_VERTEX];
Vector2f last_frame_vertex[MAX_VERTEX];
int total_vertex = 0;

TFT_HX8357_Due tft = TFT_HX8357_Due();

Matrix4f m_world;

cube obj;

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

    if (!is_hidden(v0, v1, v2))
    {
      tft.drawTriangle(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y, color);
    }
  }
}

void clear_frame()
{
  int min_x = 480, max_x = 0, min_y = 320, max_y = 0;
  if (total_vertex < 1)
    return;
  Vector2f point;
  // get bounding box
  for (int i = 0; i < total_vertex; i++)
  {
    point.x = current_frame_vertex[i].x;
    point.y = current_frame_vertex[i].y;
    if (point.x < min_x)
      min_x = floor(point.x);
    if (point.x > max_x)
      max_x = ceil(point.x);
    if (point.y < min_y)
      min_y = floor(point.y);
    if (point.y > max_y)
      max_y = ceil(point.y);
  }
  int w = ceil(max_x - min_x);
  int h = ceil(max_y - min_y);
  tft.fillRect(min_x - 5, min_y - 5, w + 20, h + 20, WHITE);
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
  total_vertex += obj.vertex_counts;
}

void loop(void)
{
  int start = millis();
  m_world = mMultiply(mRotateY(1), m_world);

  // for future, z-buffer
  for (int i = 0; i < obj.vertex_counts; i++)
  {
    // no camera
    // project to screen space directly
    Vector3f v = m_mul_v(m_world, obj.vertex_pos[i]);
    current_frame_vertex[i].x = (FOV * v.x) / (FOV + v.z) + HALF_SCREEN_WIDTH;
    current_frame_vertex[i].y = (FOV * v.y) / (FOV + v.z) + HALF_SCREEN_HEIGHT;
  }

  if (!is_vertices_equal(total_vertex, last_frame_vertex, current_frame_vertex))
  {
    clear_frame();
    draw_triangles(obj.triangle_counts, current_frame_vertex, obj.indices, BLACK);
    delay(16);
    copy_vertices(total_vertex, last_frame_vertex, current_frame_vertex);
  }

  int end = millis();
  // Serial.println(1000 / (end - start));
}
