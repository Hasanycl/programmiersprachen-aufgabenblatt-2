#include"circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>


Circle::Circle():

	    center_{ 0.0f , 0.0f },
		radius_{ 0.0f }{}



Circle::Circle(Vec2 const& center, float radius , Color const& color):

	    center_{ center }, 
		radius_{ radius },
	    color_{ color }{}


float Circle::circumference () const
{
	return 2 * M_PI * radius_;
}

void Circle::draw(Window const& win) const
{
	draw(win, 1.0f);

}


void Circle::draw(Window const& win, float thickness) const {
	Vec2 start_point{ center_.x , center_.y + radius_ };
	int NUMBER_OF_SEGMENTS = 500;
	Mat2 rotationmat = make_rotation_mat2(360 * M_PI / 180 / NUMBER_OF_SEGMENTS);

	for (int i = 0; i < NUMBER_OF_SEGMENTS; i++) {
		Vec2 end_point{ start_point };
		end_point -= center_;
		end_point = rotationmat * end_point;
		end_point += center_;
		win.draw_line(start_point.x, start_point.y, end_point.x, end_point.y, color_.r, color_.g, color_.b, thickness);
		start_point = end_point;
	}
}