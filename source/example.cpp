#include "window.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  //old examples
 // Circle c5{ {400.0f,400.0f} , {90.0f }, { 0.5f , 0.3f , 0.4f }};
  //Rect rect1{ {300.0f , 300.0f}, {200.0f, 200.0f}, {0.2f, 0.2f, 0.4f} };

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    //old examples
    //c5.draw(win);
   // rect1.draw(win);

    Rect r1{ {50.0f,50.0f},{100.0f,100.0f}, {0.2f,0.2f,0.2f} };
    Rect r2{ {300.0f,328.0f},{551.0f,502.0f}, {0.3f,0.8f,0.1f} };
    Circle c1{ {158.0f,200.0f}, 45.0f, {0.3,0.7,0.9} };
    Circle c2{ {390.0f,270.0f}, 72.0f, {0.3f,0.1f,0.3f} };

    r1.draw(win, 1.2f);
    r2.draw(win, 1.7f);

    c1.draw(win, 0.2f);
    c2.draw(win, 1.2f);

    std::array<Circle, 2> myCircles{ c1, c2 };
    std::array<Rect, 2> myRectangles{ r1, r2 };


    for (Circle c : myCircles) {
        if (c.is_inside({ (float)mouse_position.first,(float)mouse_position.second })) {

            c.draw(win, 3.0f);
        }
        
      }

    for (Rect r : myRectangles) {

        if (r.is_inside({ (float)mouse_position.first,(float)mouse_position.second })) {

            r.draw(win, 3.0f);
        }
    }


    win.update();
  }

  return 0;
}
