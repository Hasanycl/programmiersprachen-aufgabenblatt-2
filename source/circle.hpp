#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle
{
	  Vec2 center_ ;
	  float radius_;


    public:
	  
		 Circle();

	     Circle(Vec2 const& center, float radius);

		 float circumference() const ;



};








#endif 
