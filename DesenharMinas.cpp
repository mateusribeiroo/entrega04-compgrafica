#include <iostream>
#include <GL/glut.h>
#include <math.h>

void DesenharMinas(void) {
	glViewport(0, 0, 500, 500);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    	glBegin(GL_TRIANGLES);
		glVertex2f(300 + 0.0,           200 + 100.0);
		glVertex2f(300 + (100.0+0.0)/2, 200 + 200.0);
		glVertex2f(300 + 100.0,         200 + 100.0);
	glEnd();
	glFlush();
}

