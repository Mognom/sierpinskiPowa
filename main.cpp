#include <math.h>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <GL/gl.h>
#include <GL/glut.h>
#include "sierpinski.h"
using namespace std;

std::list<Triangulo> l;

void reshape3d (int w, int h) // VENTANA GRÁFICA  3D
{
    glViewport( 0, 0, w, h );
    glClearColor (0,0,0,0);
    glClear (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    if ( h==0 ) h=1;
    gluPerspective ( 60, ( float ) w / ( float ) h, 1, 1000 );
    gluLookAt(0.4,0.5,-1,0.4,0.5,0,1,0,0);
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity( );
}

void ejesdecolores(void){
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glEnd();
}

void dibujar(){
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    //ejesdecolores();
    glColor3f(0.98f,0.73f,0.85f);
	
	#pragma omp parallel
	while(!l.empty()){
		Triangulo actual = l.front();
		l.pop_front();
		
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glVertex2f(actual.getA().getX(),actual.getA().getY());
        glVertex2f(actual.getB().getX(),actual.getB().getY());
        glVertex2f(actual.getC().getX(),actual.getC().getY());
        glEnd();

        glPopMatrix();
    }
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    Punto a((0-0.5) * 1.5, (0-0.5) * 1.5);
    Punto b((0.5-0.5) * 1.5, ((sqrt(3)/2) - 0.5) * 1.5);
    Punto c((1-0.5) * 1.5, (0-0.5) * 1.5);

    Triangulo t0(a,b,c);
    clock_t reloj;
    reloj = clock();
    Sierpinski s(t0);
    reloj = clock() - reloj;
    l = s.getLista();
    printf("%i\n",l.size());
    printf("Sierpinski nos llevo: %f segundos\n",((float)reloj)/CLOCKS_PER_SEC);
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600,600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Sierpinski");
    reloj = clock();
    dibujar();
    reloj = clock() - reloj;
    printf("Dibujar nos llevo: %f segundos\n",((float)reloj)/CLOCKS_PER_SEC);
    glutMainLoop();
    return 0;
}

