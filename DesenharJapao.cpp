#include <iostream>
#include <GL/glut.h>
#include <math.h>

//  /*
void DesenharJapao(void){
	glViewport(0, 0, 500, 500);
	double PI = 3.14159265358979323846;
	double r = 200; 
	int nDots = 100; 
	double x = 0, y = 0, theta = 0, p = 0;
	p = 2 * PI / nDots;
	theta = 2 * PI / nDots;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		for (int i = 0; i <= nDots; i++) {
			x = r * cos(theta);
			y = r * sin(theta);
			theta += p;
			glVertex2i(x, y);
		}
	glEnd();
	glFlush();
}
//  */

  /*
void DesenharJapao(void){
	glViewport(0, 0, 500, 500);
	double PI = 3.14159265358979323846;
	double r = 200; 
	int nDots = 100; 
	double x = 0, y = 0, theta = 0, p = 0;  double centrox = 300.0, centroy = 300.0; // diferente da versão original
	p = 2 * PI / nDots;
	theta = 2 * PI / nDots;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		for (int i = 0; i <= nDots; i++) {
			x = r * cos(theta) + centrox; // diferente da versão original 
			y = r * sin(theta) + centroy; // gluOrtho2D(0.0, 600.0, 0.0, 600.0); em Inicializa.cpp
			theta += p;
			glVertex2i(x, y);
		}
	glEnd();
	glFlush();
}
  */

