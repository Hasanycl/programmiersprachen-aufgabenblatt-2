#include"circle.hpp"


Circle::Circle():

	    center_{ 0.0f , 0.0f },
		radius_{ 0.0f }{}



Circle::Circle(Vec2 const& center, float radius):

	    center_{ center }, 
		radius_{ radius }{}
