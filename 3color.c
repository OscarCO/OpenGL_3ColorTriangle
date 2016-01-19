/*
This program was made by Oscar C. Ortiz

compile in C with GCC 
command line compile arguments: gcc 3color.c -o gl -lGL -lGLU -lglut
*/

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

void init (void)
{

glClearColor(0.0,0.0,0.0,0.0);
glShadeModel(GL_SMOOTH);

}

void display(void)
{

glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_TRIANGLES);


glColor3f(1.0,0.0,0.0);
glVertex3f(0.0, 25.0, 0.0);

glColor3f(0.0,1.0,0.0);
glVertex3f(25.0, 0.0, 0.0);

glColor3f(0.0,0.0,1.0);
glVertex3f(-25.0, 0.0, 0.0);


glEnd();

glFlush ();

}



void reshape(int w, int h)
{

glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

}



int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(450, 450);
glutInitWindowPosition(250,250);
glutCreateWindow(argv[0]);

init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;

}
