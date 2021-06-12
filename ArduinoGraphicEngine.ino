#include <TFT_HX8357_Due.h>
#include "color.h"
#include "geometry.h"
#include "math.h"

#define K1 10
#define K2 11
#define K3 12
#define K4 13

#define FOV 300
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define HALF_SCREEN_WIDTH 240
#define HALF_SCREEN_HEIGHT 160
#define MAX_VERTEX 2000
#define OFFSET 80
#define GUI_WIDTH 160
#define GUI_BLOCK 60
#define GUI_H_INTER 13
#define GUI_V_INTER 16

#define INDEX_CUBE 1
#define INDEX_SEPHERE 2
#define INDEX_CONE 3
#define INDEX_FACE 4
#define INDEX_SMALLBUNNY 5
#define INDEX_BUNNY 6
#define INDEX_EDITOR 7
#define INDEX_RUNNING 8

Vector2f current_frame_vertex[MAX_VERTEX];
Vector2f last_frame_vertex[MAX_VERTEX];
int total_vertex = 0;

TFT_HX8357_Due tft = TFT_HX8357_Due();

Matrix4f m_world;

cube obj;

void gui_block(unsigned char index, int block_x, int block_y, bool seleted)
{
  switch (index)
  {
  case INDEX_CUBE:
    tft.fillRect(block_x + 10, block_y + 10, 40, 40, BLACK);
    break;
  case INDEX_SEPHERE:
    tft.fillCircle(block_x + 30, block_y + 30, 20, BLACK);
    break;
  case INDEX_CONE:
    tft.fillTriangle(block_x + 30, block_y + 10, block_x + 10, block_y + 50, block_x + 50, block_y + 50, BLACK);
    break;
  case INDEX_FACE:
    tft.fillTriangle(block_x + 10, block_y + 20, block_x + 20, block_y + 50, block_x + 20, block_y + 10, BLACK);
    tft.fillRect(block_x + 20, block_y + 10, 20, 40, BLACK);
    tft.fillTriangle(block_x + 40, block_y + 10, block_x + 40, block_y + 50, block_x + 50, block_y + 20, BLACK);
    break;
  case INDEX_SMALLBUNNY:
    tft.fillTriangle(block_x + 10, block_y + 30, block_x + 15, block_y + 32, block_x + 15, block_y + 28, BLACK);
    tft.fillRect(block_x + 15, block_y + 26, 35, 10, BLACK);
    tft.fillRect(block_x + 37, block_y + 16, 2, 10, BLACK);
    tft.fillRect(block_x + 43, block_y + 16, 2, 10, BLACK);
    break;
  case INDEX_BUNNY:
    tft.fillTriangle(block_x + 5, block_y + 30, block_x + 10, block_y + 28, block_x + 10, block_y + 38, BLACK);
    tft.fillRect(block_x + 10, block_y + 26, 45, 16, BLACK);
    tft.fillRect(block_x + 30, block_y + 10, 8, 16, BLACK);
    tft.fillRect(block_x + 42, block_y + 10, 8, 16, BLACK);
    break;
  case INDEX_EDITOR:
    tft.setCursor(block_x + 7, block_y + 20);
    tft.setTextSize(2);
    tft.println("Edit");
    break;
  case INDEX_RUNNING:
    tft.setCursor(block_x + 5, block_y + 20);
    tft.setTextSize(3);
    tft.println("Run");
    break;
  default:
    break;
  }
}

void gui()
{
  tft.fillRect(0, 0, GUI_WIDTH, 320, OLIVE);
  int block_x = GUI_H_INTER;
  int block_y = 0;
  // draw first column
  for (unsigned char i = 1; i <= 4; i++)
  {
    block_y = i * GUI_V_INTER + (i - 1) * GUI_BLOCK;
    tft.fillRect(block_x, block_y, GUI_BLOCK, GUI_BLOCK, WHITE);
    gui_block(i, block_x, block_y, false);
  }
  block_x = 2 * GUI_H_INTER + GUI_BLOCK;
  for (unsigned char i = 1; i <= 4; i++)
  {
    block_y = i * GUI_V_INTER + (i - 1) * GUI_BLOCK;
    tft.fillRect(block_x, block_y, GUI_BLOCK, GUI_BLOCK, WHITE);
    gui_block(i + 4, block_x, block_y, false);
  }
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

  tft.fillScreen(0xffff);
  gui();
  m_world = mMultiply(mScale(0.3), m_world);
  m_world = mMultiply(mTranslate(0, 0, 10), m_world);
  total_vertex += obj.vertex_counts;
}

void loop(void)
{
  int start = millis();
  m_world = mMultiply(mRotateY(1), m_world);
  for (int i = 0; i < obj.vertex_counts; i++)
  {
    Vector4f v = m4_mul_v3(m_world, obj.vertex_pos[i]);
    current_frame_vertex[i].x = ((FOV * v.x) / (FOV + v.z) + HALF_SCREEN_WIDTH) + OFFSET;
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
