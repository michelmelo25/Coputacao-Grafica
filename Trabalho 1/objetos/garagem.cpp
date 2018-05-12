#include "obj/garagem.h"

Garagem::Garagem(){
    this->xmin = -2;
    this->xmax = -3;
    this->ymin = 0;
    this->ymax = 1;
    this->zmin = 0;
    this->zmax = -1;
}

void Garagem::garagem(){
    glEnable(GL_CULL_FACE);
    //Lateral Direita
    glPushMatrix();
    Objeto::desenha();
        glPushMatrix();
            glBegin(GL_QUADS);
              glNormal3f(1.,0.,0.);
              glVertex3f(xmin, ymin, zmin);
              glVertex3f(xmin, ymax, zmin);
              glVertex3f(xmin, ymax, zmax-1);
              glVertex3f(xmin, ymin, zmax-1);

              glVertex3f(xmin, ymin, zmax-1);
              glVertex3f(xmin, ymax, zmax-1);
              glVertex3f(xmin, ymax, zmin);
              glVertex3f(xmin, ymin, zmin);
            glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1,0,0);
            glBegin(GL_QUADS);
              glNormal3f(1.,0.,0.);
              glVertex3f(xmin, ymin, zmin);
              glVertex3f(xmin, ymax, zmin);
              glVertex3f(xmin, ymax, zmax-1);
              glVertex3f(xmin, ymin, zmax-1);

              glVertex3f(xmin, ymin, zmax-1);
              glVertex3f(xmin, ymax, zmax-1);
              glVertex3f(xmin, ymax, zmin);
              glVertex3f(xmin, ymin, zmin);
            glEnd();
        glPopMatrix();

        //Fundo
        glPushMatrix();
            glBegin(GL_QUADS);
                glNormal3f(1.,0.,0.);
                glVertex3f(xmin, ymin, zmax-1);
                glVertex3f(xmin, ymax, zmax-1);
                glVertex3f(xmax, ymax, zmax-1);
                glVertex3f(xmax, ymin, zmax-1);

                glVertex3f(xmax, ymin, zmax-1);
                glVertex3f(xmax, ymax, zmax-1);
                glVertex3f(xmin, ymax, zmax-1);
                glVertex3f(xmin, ymin, zmax-1);
            glEnd();
        glPopMatrix();

        //Teto
        glPushMatrix();
            glBegin(GL_QUADS);
                glNormal3f(1.,0.,0.);
                glVertex3f(xmin, ymax, zmin);
                glVertex3f(xmin, ymax, zmax-1);
                glVertex3f(xmax, ymax, zmax-1);
                glVertex3f(xmax, ymax, zmin);

                glVertex3f(xmax, ymax, zmin);
                glVertex3f(xmax, ymax, zmax-1);
                glVertex3f(xmin, ymax, zmax-1);
                glVertex3f(xmin, ymax, zmin);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}

void Garagem::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0.7,1,1);
    }
    glPushMatrix();
        garagem();
    glPopMatrix();
}
