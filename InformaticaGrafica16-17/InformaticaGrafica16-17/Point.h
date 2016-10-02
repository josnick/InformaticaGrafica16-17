#pragma once

#ifndef __POINT_H__
#define __POINT_H__

#include "Point.h"
#include <math.h>       /* sqrt */

struct point
{
	float x, y, z;
	//inicializaaa el struct a 1,1,1
	point() {
		x = 1.0;
		y = 1.0;
		z = 1.0;

	}
	//inicializa el struct a x,y,z
	point(float xpos,float ypos,float zpos) {
		x = xpos;
		y = ypos;
		z = zpos;

	}
	//calcula el modulo con otro punto
	float  distance(point p) {return sqrt(pow(x-p.x,2) + pow(y - p.y,2)  + pow(z - p.z,2));}
	void   print() { std::cout << x << "," << y << "," << z << std::endl; }


	//sobreescritura de operandos
	point& operator=(point p)  { return point{ p.x,p.y,p.z }; }
	point& operator+(point p)  { return point{ x += p.x, y += p.y, z += p.z }; }
	point& operator-(point p)  { return point{ x -= p.x, y -= p.y, z -= p.z }; }
	point& operator*(point p)  { return point{ x*p.z - z*p.y,z*p.x - x*p.z,x*p.y - y*p.x }; }
	point& operator*(float f)  { return point{ x *= f,y *= f,z *= f }; }
	point& operator*(int i)    { return point{ x *= i,y *= i,z *= i }; }
	point& operator/(point p)  { return point{ x /= p.x,y /= p.y, z /= p.z }; }
};



#endif //  __VECTOR_H_ 
