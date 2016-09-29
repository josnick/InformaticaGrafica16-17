#include <iostream>
#include <time.h>
#include "Vector.h"
#include "Point.h"

using namespace std;

void wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}


int main() {
	point p1 = { 1.0f,2.0f,0.0f };
	point p2 = { 2.0f,2.0f,0.0f };


	vector v1 = { 0.0f,0.0f,1.0f };
	vector v2 = { 0.0f,1.0f,0.0f };

	vector v3 = v1*v2;
	v3.print();

	wait(10);
	return 1;
}