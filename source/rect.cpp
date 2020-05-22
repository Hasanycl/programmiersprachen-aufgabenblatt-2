#include"rect.hpp"


Rect::Rect():

	min_{ 0.0f , 0.0f },
	max_{ 0.0f , 0.0f }{}



Rect::Rect(Vec2 const& min, Vec2 const& max):

    min_{ min },
	max_{ max }{}


float Rect::circumference_rect() const
{
	return 2 * (max_.x - min_.x + max_.y - min_.y);
   
}
