#ifndef MOVESHAPE_H
#define MOVESHAPE_H
#include "D:/GLFW/include/GLFW/glfw3.h"

extern int keyVal;

class Circle {
	GLfloat radius;
	GLfloat red, green, blue;
	GLfloat horiz, vert;
	
	void setColor();

	public:
		Circle(GLfloat rad, GLfloat r, GLfloat g, GLfloat b);
		
		void drawCircle(GLfloat x, GLfloat y);
		void moveCircle(int key);
};

#endif