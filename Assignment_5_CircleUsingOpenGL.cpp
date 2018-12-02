#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

#define Pi 3.1415926535
float x, y, radius;

void init(){
    glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void circleDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

	int i, sides = 100;

	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.3, 0.5);
		glVertex2f(x, y);
		for(i = 0; i <= sides; i++) {
			glVertex2f(x + (radius*cos(2*i*Pi/sides)), y + (radius*sin(2*i*Pi/sides)));
		}
	glEnd();

	glFlush();
}

void circle(float cx, float cy, float rad){
    x = cx;
    y = cy;
    radius = rad;
    glutDisplayFunc(circleDisplay);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 200);

    glutCreateWindow("Circle");

    init();

    circle(200.0, 200.0, 190.0);

    glutMainLoop();

    return 0;
}
