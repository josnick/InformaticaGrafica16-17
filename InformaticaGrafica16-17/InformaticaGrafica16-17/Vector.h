#pragma once

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Point.h"
#include <iostream>
#include <math.h>       /* sqrt */
# define M_PI           3.14159265358979323846  /* pi */

struct vector {
	float x, y, z;
	//inicializa vector a 1,1,1
	vector() {
		x = 1.0;
		y = 1.0;
		z = 1.0;
	}

	vector(float xdir, float ydir, float zdir) {
		x = xdir;
		y = ydir;
		z = zdir;
	}
	//Crea un vector a partir de dos puntos
	vector(point p1, point p2) {
		x = p2.x - p1.x;
		y = p2.y - p1.y;
		z = p2.z - p1.z;
	}

	float module() { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }
	float scalarProduct(vector v) { return (x*v.x) + (y*v.y) + (z*v.z); }
	float angle(vector v) { return acos(scalarProduct(v) / (module()*v.module())) * 180 / M_PI; }
	void print() {std::cout << x << "," << y << "," << z << std::endl;}

	//sobreescritura de operandos
	vector& operator=(vector v) { return vector{ v.x,v.y,v.z }; }
	vector& operator+(vector v) { return vector{ x += v.x, y += v.y, z += v.z }; }
	vector& operator-(vector v) { return vector{ x -= v.x, y -= v.y, z -= v.z}; }
	vector& operator*(vector v) { return vector{ x*v.z - z*v.y,z*v.x - x*v.z,x*v.y - y*v.x }; } //prodcuto vectorial (normal)
	vector& operator*(float f)  { return vector{ x *= f,y *= f,z *= f }; }
	vector& operator*(int i)    { return vector{ x *= i,y *= i,z *= i }; }
	vector& operator/(vector v) { return vector{ x /= v.x,y /= v.y, z /= v.z }; }
};




#endif //  __VECTOR_H_ 
