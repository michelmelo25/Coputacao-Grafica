#include "obj/estrada.h"

GLfloat xmin = 5;
GLfloat ymin = 0;
GLfloat zmin = 3;
GLfloat xmax = -5;
GLfloat ymax = 0;
GLfloat zmax = 5;

Estrada::Estrada(){
    glEnable(GL_CULL_FACE);

    glPushMatrix();
    glColor3d(0,0,0);
    glTranslatef(0,0,1);
        glBegin(GL_QUADS);
          glNormal3f(0.,0.,1.);
          glVertex3f(xmax, ymin, zmin);
          glVertex3f(xmax, ymax, zmax);
          glVertex3f(xmin, ymin, zmax);
          glVertex3f(xmin, ymin, zmin);

          glVertex3f(xmin, ymin, zmin);
          glVertex3f(xmin, ymin, zmax);
          glVertex3f(xmax, ymax, zmax);
          glVertex3f(xmax, ymin, zmin);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,1,0);
    glTranslatef(0,0,1);
        glBegin(GL_QUADS);
          glNormal3f(0.,0.,1.);
          glVertex3f(xmax, ymin+0.001, zmin+0.9);
          glVertex3f(xmax, ymax+0.001, zmax-0.9);
          glVertex3f(xmin, ymin+0.001, zmax-0.9);
          glVertex3f(xmin, ymin+0.001, zmin+0.9);
        glEnd();
    glPopMatrix();


}

void Estrada::desenha(){
    //desenhando objeto
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(1,0,0);
    }
    glPushMatrix();
        Estrada();
    glPopMatrix();
glPopMatrix();
}
