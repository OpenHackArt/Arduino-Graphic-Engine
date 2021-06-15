#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>

#define TFT_CS 9
#define TFT_DC 7
#define TFT_LED 8
#define TFT_RST 6

#define BTN_UP 10
#define BTN_LEFT 11
#define BTN_DOWN 12
#define BTN_RIGHT 13

int btn_up_state, btn_left_state, btn_down_state, btn_right_state;
int rays_per_pixel = 8;
int render_speed = 1;
int config_state = 0;
int camera_x = 0, camera_y = 0, camera_z = 3;

ILI9488 display = ILI9488(TFT_CS, TFT_DC, TFT_RST);

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
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(BTN_LEFT, INPUT);
  pinMode(BTN_RIGHT, INPUT);
  // doRaytrace(1, 480, 320, 1); // full 320x240 1 sample
  //                             //  doRaytrace(1,480,320,4); // fast preview
  //                             //  doRaytrace(1,480,320,2); // slower preview
  //                             //  doRaytrace(8,480,320,1); // Very High Quality
  Serial.println(F("Done!"));
  Serial.print(F("Time = "));
  Serial.print((millis() - t) / 1000);
  Serial.println(F(" seconds"));
}

void config()
{
  switch (config_state)
  {
  case 0:
    display.setCursor(50, 100);
    display.setTextSize(4);
    display.println("Render Quality: ");
    display.setCursor(50, 200);
    display.println(rays_per_pixel);
    return;
  case 1:
    display.setCursor(50, 100);
    display.setTextSize(4);
    display.println("Rendering Speed: ");
    display.setCursor(50, 200);
    display.println(render_speed);
    return;
  case 2:
    display.setCursor(50, 100);
    display.setTextSize(4);
    display.println("Camera X: ");
    display.setCursor(50, 200);
    display.println(camera_x);
    return;
  case 3:
    display.setCursor(50, 100);
    display.setTextSize(4);
    display.println("Camera Y: ");
    display.setCursor(50, 200);
    display.println(camera_y);
    return;
  case 4:
    display.setCursor(50, 100);
    display.setTextSize(4);
    display.println("Camera Z: ");
    display.setCursor(50, 200);
    display.println(camera_z);
    return;
  default:
    break;
  }
}

void change_command(bool plus)
{
  switch (config_state)
  {
  case 0:
    if (plus)
    {
      rays_per_pixel = (rays_per_pixel % 8) + 1;
    }
    else
    {
      if (rays_per_pixel == 1)
        rays_per_pixel = 8;
      else
        rays_per_pixel--;
    }
    return;
  case 1:
    if (plus)
    {
      render_speed = (render_speed % 4) + 1;
    }
    else
    {
      if (render_speed == 1)
        render_speed = 4;
      else
        render_speed--;
    }
    return;
  case 2:
    if (plus)
    {
      camera_x++;
    }
    else
    {
      if (camera_x != 0)
        camera_x--;
    }
    return;
  case 3:
    if (plus)
    {
      camera_y++;
    }
    else
    {
      if (camera_y != 0)
        camera_y--;
    }
    return;
  case 4:
    if (plus)
    {
      camera_z++;
    }
    else
    {
      if (camera_z != 0)
        camera_z--;
    }
    return;
  default:
    break;
  }
}

bool is_press = false;

void loop(void)
{
  btn_up_state = digitalRead(BTN_UP);
  btn_left_state = digitalRead(BTN_LEFT);
  btn_down_state = digitalRead(BTN_DOWN);
  btn_right_state = digitalRead(BTN_RIGHT);
  if (is_press)
  {
    display.fillScreen(0x0000);
  }

  config();
  if (!btn_up_state)
  {
    change_command(true);
    is_press = true;
    delay(300);
  }
  else if (!btn_down_state)
  {
    change_command(false);
    is_press = true;
    delay(300);
  }
  else if (!btn_left_state)
  {
    config_state == 0 ? config_state = config_state : config_state--;
    is_press = true;
    delay(300);
  }
  else if (!btn_right_state)
  {
    config_state++;
    is_press = true;
    delay(300);
  }
  else
  {
    is_press = false;
  }
  if (config_state >= 5)
  {
    is_press = false;
    display.setTextSize(1);
    btn_right_state = 1;
    doRaytrace(rays_per_pixel, 480, 320, render_speed, camera_x, camera_y, camera_z);
    while (btn_right_state)
    {
      btn_right_state = digitalRead(BTN_RIGHT);
    }
    config_state = 0;
  }
}