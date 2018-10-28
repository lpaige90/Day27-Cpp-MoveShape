#include "moveshape.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

int keyVal;

Circle::Circle(GLfloat rad, GLfloat r, GLfloat g, GLfloat b) {
	radius = rad;
	red = r;
	green = g;
	blue = b;
	horiz = 0.0f;
	vert = 0.0f;
}

void Circle::setColor() {
	glColor3f(red, green, blue);
}

void Circle::drawCircle(GLfloat x, GLfloat y) {
	glBegin(GL_POLYGON);
	this->setColor();
	for (int i = 0; i < 360; ++i) {
		float degToRad = i * (3.14159 / 180.0);
		glVertex2f(cos(degToRad) * this->radius + x, sin(degToRad) * this->radius + y);
	}
	glEnd();
}

void Circle::moveCircle(int key) {
	if (key == GLFW_KEY_LEFT) {
		horiz = horiz - 0.05f;
		std::cout << horiz;
		this->drawCircle(horiz, vert);
		keyVal = horiz;
	}
	else if (key == GLFW_KEY_RIGHT) {
		horiz = horiz + 0.05f;
		this->drawCircle(horiz, vert);
		keyVal = horiz;
	}
	else if (key == GLFW_KEY_UP) {
		vert = vert + 0.05f;
		this->drawCircle(horiz, vert);
		keyVal = vert;
	}
	else if (key == GLFW_KEY_DOWN) {
		vert = vert - 0.05f;
		this->drawCircle(horiz, vert);
		keyVal = vert;
	}
	else {
		this->drawCircle(horiz, vert);
	}
}

