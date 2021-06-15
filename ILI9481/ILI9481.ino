#include <TFT_HX8357_Due.h>
#include "color.h"
#include "geometry.h"
#include "math.h"

#define K1 10
#define K2 11
#define K3 12
#define K4 13

#define BTN_UP K3
#define BTN_LEFT K4
#define BTN_DOWN K1
#define BTN_RIGHT K2

#define JOY_STICK_X 57
#define JOY_STICK_Y 58

#define FOV 60
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define HALF_SCREEN_WIDTH 240
#define HALF_SCREEN_HEIGHT 160
#define MAX_VERTEX 2000
#define MAX_OBJ 10
#define OFFSET 80
#define GUI_WIDTH 160
#define GUI_BLOCK 60
#define GUI_H_INTER 13
#define GUI_V_INTER 16

TFT_HX8357_Due tft = TFT_HX8357_Due();

unsigned char select_index = 1; // from 1 to 8
int total_vertex = 0;

Vector2f current_frame_vertex[MAX_VERTEX];
Vector2f last_frame_vertex[MAX_VERTEX];

Matrix4f m_world;

int btn_up, btn_down, btn_left, btn_right;

void gui_block(unsigned char index, int block_x, int block_y, bool seleted)
{
  int16_t color;
  if (seleted)
    color = ORANGE;
  else
    color = BLACK;
  switch (index)
  {
  case INDEX_CUBE:
    tft.fillRect(block_x + 10, block_y + 10, 40, 40, color);
    break;
  case INDEX_SPHERE:
    tft.fillCircle(block_x + 30, block_y + 30, 20, color);
    break;
  case INDEX_CONE:
    tft.fillTriangle(block_x + 30, block_y + 10, block_x + 10, block_y + 50, block_x + 50, block_y + 50, color);
    break;
  case INDEX_FACE:
    tft.fillTriangle(block_x + 10, block_y + 20, block_x + 20, block_y + 50, block_x + 20, block_y + 10, color);
    tft.fillRect(block_x + 20, block_y + 10, 20, 40, color);
    tft.fillTriangle(block_x + 40, block_y + 10, block_x + 40, block_y + 50, block_x + 50, block_y + 20, color);
    break;
  case INDEX_SMALLBUNNY:
    tft.fillTriangle(block_x + 10, block_y + 30, block_x + 15, block_y + 32, block_x + 15, block_y + 28, color);
    tft.fillRect(block_x + 15, block_y + 26, 35, 10, color);
    tft.fillRect(block_x + 37, block_y + 16, 2, 10, color);
    tft.fillRect(block_x + 43, block_y + 16, 2, 10, color);
    break;
  case INDEX_BUNNY:
    tft.fillTriangle(block_x + 5, block_y + 30, block_x + 10, block_y + 28, block_x + 10, block_y + 38, color);
    tft.fillRect(block_x + 10, block_y + 26, 45, 16, color);
    tft.fillRect(block_x + 30, block_y + 10, 8, 16, color);
    tft.fillRect(block_x + 42, block_y + 10, 8, 16, color);
    break;
  case INDEX_MONKEY:
    tft.setCursor(block_x + 12, block_y + 15);
    tft.setTextSize(4);
    tft.println("M");
    break;
  case INDEX_TORUS:
    tft.setCursor(block_x + 12, block_y + 15);
    tft.setTextSize(4);
    tft.println("T");
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
    int16_t bg_color = i == select_index ? MAROON : WHITE;
    block_y = i * GUI_V_INTER + (i - 1) * GUI_BLOCK;
    tft.fillRect(block_x, block_y, GUI_BLOCK, GUI_BLOCK, bg_color);
    gui_block(i, block_x, block_y, i == select_index);
  }
  block_x = 2 * GUI_H_INTER + GUI_BLOCK;
  for (unsigned char i = 1; i <= 4; i++)
  {
    int16_t bg_color = i + 4 == select_index ? MAROON : WHITE;
    block_y = i * GUI_V_INTER + (i - 1) * GUI_BLOCK;
    tft.fillRect(block_x, block_y, GUI_BLOCK, GUI_BLOCK, bg_color);
    gui_block(i + 4, block_x, block_y, i + 4 == select_index);
  }
}

void too_big_warning()
{
  tft.fillRect(GUI_WIDTH, 0, SCREEN_WIDTH - GUI_WIDTH, SCREEN_HEIGHT, WHITE);
  tft.setCursor(GUI_WIDTH + 10, (SCREEN_HEIGHT / 2) - 10);
  tft.setTextSize(6);
  tft.setTextColor(BLUE);
  tft.println("Too Big");
}

void draw_mesh(int triangle_cnts, const Vector3i *indices, const uint16_t color)
{
  for (int i = 0; i < triangle_cnts; i++)
  {
    Vector3i index = indices[i];
    Vector2f v0 = current_frame_vertex[index.x];
    Vector2f v1 = current_frame_vertex[index.y];
    Vector2f v2 = current_frame_vertex[index.z];

    if (v0.x < GUI_WIDTH || v1.x < GUI_WIDTH || v2.x < GUI_WIDTH || v0.x > SCREEN_WIDTH || v1.x > SCREEN_WIDTH || v2.x > SCREEN_WIDTH)
    {
      too_big_warning();
      return;
    }

    if (v0.y < 0 || v1.y < 0 || v2.y < 0 || v0.y > SCREEN_HEIGHT || v1.y > SCREEN_HEIGHT || v2.y > SCREEN_HEIGHT)
    {
      too_big_warning();
      return;
    }

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

void show_fps(int start, int end)
{
  tft.fillRect(460, 0, 20, 20, WHITE);
  tft.setCursor(460, 3);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.println(1000 / (end - start));
}

void setup()
{
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_LEFT, INPUT);
  pinMode(BTN_RIGHT, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(JOY_STICK_X, INPUT);
  pinMode(JOY_STICK_Y, INPUT);
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(0xffff);
  gui();
  m_world = mMultiply(mScale(0.3), m_world);
}

bool is_press = false;

void loop(void)
{
  btn_down = digitalRead(BTN_DOWN);
  btn_up = digitalRead(BTN_UP);
  btn_left = digitalRead(BTN_LEFT);
  btn_right = digitalRead(BTN_RIGHT);
  if (!btn_up)
  {
    if (select_index != 1)
    {
      select_index--;
      is_press = true;
      delay(300);
    }
  }
  else if (!btn_left)
  {
    m_world = mMultiply(mScale(0.99), m_world);
  }
  else if (!btn_right)
  {
    m_world = mMultiply(mScale(1.01), m_world);
  }
  else if (!btn_down)
  {
    if (select_index != 8)
    {
      select_index++;
      is_press = true;
      delay(300);
    }
  }
  if (is_press)
  {
    m_world = mScale(0.3);
    tft.fillScreen(WHITE);
    gui();
  }
  is_press = false;

  int x_rotation = analogRead(JOY_STICK_X);
  int y_rotation = analogRead(JOY_STICK_Y);
  if (x_rotation > 1000)
  {
    x_rotation = -1;
  }
  else if (x_rotation < 10)
  {
    x_rotation = 1;
  }
  else
  {
    x_rotation = 0;
  }
  if (y_rotation < 10)
  {
    y_rotation = 1;
  }
  else if (y_rotation > 1000)
  {
    y_rotation = -1;
  }
  else
  {
    y_rotation = 0;
  }

  int start = millis();
  m_world = mMultiply(mRotateY(y_rotation), m_world);
  m_world = mMultiply(mRotateX(x_rotation), m_world);
  int vertex_cnts = get_vertex_cnts(select_index);
  int tri_cnts = get_triangle_cnts(select_index);
  Vector3f *pos = get_vertex_pos(select_index);
  Vector3i *indices = get_indices(select_index);
  total_vertex = vertex_cnts;
  for (int i = 0; i < vertex_cnts; i++)
  {
    Vector3f v = m_mul_v_acc(m_world, pos[i]);
    current_frame_vertex[i].x = ((FOV * v.x) / (FOV + v.z) + HALF_SCREEN_WIDTH) + OFFSET;
    current_frame_vertex[i].y = (FOV * v.y) / (FOV + v.z) + HALF_SCREEN_HEIGHT;
  }

  if (!is_vertices_equal(0, vertex_cnts, last_frame_vertex, current_frame_vertex))
  {
    clear_frame();
    draw_mesh(tri_cnts, indices, BLACK);
    delay(16);
    copy_vertices(0, vertex_cnts, last_frame_vertex, current_frame_vertex);
  }

  int end = millis();
  show_fps(start, end);
}
