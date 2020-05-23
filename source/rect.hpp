#ifndef	RECT_HPP
#define RECT_HPP
#include "vec2.hpp"
#include "color.hpp"


class Rect
{
	Vec2 min_;
	Vec2 max_;
	Color color_;


    public:

		Rect();

	    Rect(Vec2 const& min, Vec2 const& max , Color const& color);

		float circumference_rect () const;

};


#endif