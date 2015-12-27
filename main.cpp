#include <math.h>
#include <iostream>
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
    glColor3f(0.98f,0.73f,0.85f);
    //ejesdecolores();
    for (list<Triangulo>::iterator iterator = l.begin(), end = l.end(); iterator != end; ++iterator){
        glPushMatrix();

        glBegin(GL_TRIANGLES);
        glVertex2f((*iterator).getA().getX(),(*iterator).getA().getY());
        glVertex2f((*iterator).getB().getX(),(*iterator).getB().getY());
        glVertex2f((*iterator).getC().getX(),(*iterator).getC().getY());
        glEnd();

        glPopMatrix();
    }
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    Punto a(0,0);
    Punto b(sqrt(3)/2,0.5);
    Punto c(0,1);

    Triangulo t0(a,b,c);
    Sierpinski s(t0);
    l = s.getLista();
    printf("%i\n",l.size());
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600,600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Sierpinski");
    glutDisplayFunc(dibujar);
    glutReshapeFunc(reshape3d);
    glutMainLoop();
    return 0;
}

