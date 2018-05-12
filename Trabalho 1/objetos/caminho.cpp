#include "obj/caminho.h"

Caminho::Caminho(){
    this->xmin = -2;
    this->xmax = -3;
    this->ymin = 0;
    this->ymax = 0;
    this->zmin = 0;
    this->zmax = 1;
}

void Caminho::caminho(){
    glEnable(GL_CULL_FACE);
    //Lateral Direita
    glPushMatrix();
        glColor3d(0.4,0.4,0.4);
        glPushMatrix();
            glBegin(GL_QUADS);
              glNormal3f(1.,0.,0.);
              glVertex3f(xmin, ymin, zmin);
              glVertex3f(xmax, ymin, zmin);
              glVertex3f(xmax, ymin, zmax);
              glVertex3f(xmin, ymin, zmax);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0,0,1);
            glBegin(GL_QUADS);
              glNormal3f(1.,0.,0.);
              glVertex3f(xmin+3, ymin, zmin);
              glVertex3f(xmax, ymin, zmin);
              glVertex3f(xmax, ymin, zmax);
              glVertex3f(xmin+3, ymin, zmax);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslated(3,0,2);
            glBegin(GL_QUADS);
              glNormal3f(1.,0.,0.);
              glVertex3f(xmin, ymin, zmin-2);
              glVertex3f(xmax, ymin, zmin-2);
              glVertex3f(xmax, ymin, zmax+1);
              glVertex3f(xmin, ymin, zmax+1);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}

void Caminho::desenha(){

    glPushMatrix();
        caminho();
    glPopMatrix();
}
