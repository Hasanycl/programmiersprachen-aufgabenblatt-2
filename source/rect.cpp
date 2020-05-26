#include"rect.hpp"


Rect::Rect():

	min_{ 0.0f , 0.0f },
	max_{ 0.0f , 0.0f }{}



Rect::Rect(Vec2 const& min, Vec2 const& max , Color const& color):

    min_{ min },
	max_{ max },
	color_{ color }{}


float Rect::circumference_rect() const
{
	return 2 * (max_.x - min_.x + max_.y - min_.y);
   
}

void Rect::draw(Window const& win) const {

	draw(win, 1.0f);
}

void Rect::draw(Window const& win, float thickness) const {

	win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b , thickness);
	win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b , thickness);
	win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b , thickness);
	win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b , thickness);

}

bool Rect::is_inside(Vec2 const& point) const {
	if (point.x < max_.x && point.x > min_.x && point.y > min_.y && point.y < max_.y) {
		return true;
	}
	else return false;

}