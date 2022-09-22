#include <iostream>
#include <GL/glut.h>
#include <math.h>

void Inicializar(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLineWidth(3.0);
	glPointSize(2);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}
