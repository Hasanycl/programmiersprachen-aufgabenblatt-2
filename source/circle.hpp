#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"

class Circle
{
	  Vec2 center_ ;
	  float radius_;
	  Color color_;


    public:
	  
		 Circle();

	     Circle(Vec2 const& center, float radius , Color const& color);

		 float circumference() const ;
		 void draw(Window const& win) const;
		 void draw(Window const& win, float thickness) const;
		 bool is_inside(Vec2 const& point) const;


};








#endif 
