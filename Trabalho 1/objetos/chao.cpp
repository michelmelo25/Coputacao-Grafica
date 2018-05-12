#include "obj/chao.h"

Chao::Chao(){
    this->xmin = 5;
    this->ymin = -0.001;
    this->zmin = -3;
    this->xmax = -5;
    this->ymax = -0.001;
    this->zmax = 5;
}

void Chao::chao(){
    glEnable(GL_CULL_FACE);

    glPushMatrix();
    glColor3d(0,1,0);
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
}

void Chao::desenha(){
    //desenhando objeto
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(1,0,0);
    }
    glPushMatrix();
        chao();
    glPopMatrix();
glPopMatrix();
}
