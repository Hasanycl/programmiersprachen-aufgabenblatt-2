#include"circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>


Circle::Circle():

	    center_{ 0.0f , 0.0f },
		radius_{ 0.0f }{}



Circle::Circle(Vec2 const& center, float radius):

	    center_{ center }, 
		radius_{ radius }{}


float Circle::circumference () const
{
	return 2 * M_PI * radius_;
}