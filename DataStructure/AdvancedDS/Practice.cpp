/*

 * Practice.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: 212331148


// CPP program to demonstrate
// ambiguous nature of constructor
// with same no of parameters of same type
#include <iostream>
using namespace std;
class Point
{
	public:

	// Rectangular coordinates
	Point(float x, float y);

	// Polar coordinates (radius and angle)
	Point(float r, float a);

	// error: ‘Point::Point(float, float)’ cannot
	// be overloaded
};
int main()
{
	// Ambiguous: Which constructor to be called ?
	Point p = Point(5.7, 1.2);
	return 0;
}
*/



