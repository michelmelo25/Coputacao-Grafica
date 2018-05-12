#include "obj/bush.h"
//Grass in box.3DS
Bush::Bush(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Bush.3ds");

}

void Bush::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0.3,1,0.5);
    }
    glPushMatrix();
    Objeto::desenha();
    glPushMatrix();
        glTranslatef(-3.7,0.38,3.0);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.003,-0.05,-0.003);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();

    glPushMatrix();
//        glTranslatef(0.0,0.0,0.0);
        glTranslatef(-1.7,0.38,3.0);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.003,-0.05,-0.003);
        malha->draw();
        // Brilho do material
        especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();

    glPushMatrix();
//        glTranslatef(0.0,0.0,0.0);
        glTranslatef(2.3,0.38,3.0);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.003,-0.05,-0.003);
        malha->draw();
        // Brilho do material
        especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();

    glPushMatrix();
//        glTranslatef(0.0,0.0,0.0);
        glTranslatef(4.0,0.38,3.0);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.003,-0.05,-0.003);
        malha->draw();
        // Brilho do material
        especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
    glPopMatrix();
}
