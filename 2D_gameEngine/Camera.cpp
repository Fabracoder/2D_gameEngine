#include "Camera.h"


int x = 0;
int y = 0;
int w = 0;
int h = 0;

void getLoc(int * X, int *Y)
{
	X = &x;
	Y = &y;
}
void getSize(int * W, int *H)
{
	W = &w;
	H = &h;
}
void getCenter(int * X, int *Y)
{
	X = &x;
	Y = &y;
}
Camera::Camera()
{
	x = y = w = h = 0; 
}

int getX()
{
	return x;
}

int getY()
{
	return y;
}

int getW()
{
	return w;
}

int getH()
{
	return h;
}



Camera::~Camera()
{
}
