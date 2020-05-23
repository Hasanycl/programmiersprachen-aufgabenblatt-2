#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Circle
{
	  Vec2 center_ ;
	  float radius_;
	  Color color_;


    public:
	  
		 Circle();

	     Circle(Vec2 const& center, float radius , Color const& color);

		 float circumference() const ;



};








#endif 
