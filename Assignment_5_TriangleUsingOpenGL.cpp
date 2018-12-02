#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

float x1, y4, x2, y2, x3, y3;

void init(){
    glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void triangleDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.3, 0.5);
        glVertex2f(x1, y4);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();

    glFlush();
}

void triangle(float vx1, float vy1, float vx2, float vy2, float vx3, float vy3){
    x1 = vx1, y4 = vy1;
    x2 = vx2, y2 = vy2;
    x3 = vx3, y3 = vy3;
    glutDisplayFunc(triangleDisplay);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 200);

    glutCreateWindow("Triangle");

    init();

    triangle(10.0, 50.0, 105.3, 300.0, 200.0, 50.0);

    glutMainLoop();

    return 0;
}
