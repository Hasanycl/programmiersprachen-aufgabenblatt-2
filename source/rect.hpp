#ifndef	RECT_HPP
#define RECT_HPP
#include "vec2.hpp"


class Rect
{
	Vec2 min_;
	Vec2 max_;


    public:

		Rect();

	    Rect(Vec2 const& min, Vec2 const& max);

		float circumference_rect () const;

};


#endif