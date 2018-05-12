#include "obj/janela.h"

Janela::Janela(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Window 1.3DS");
}

void Janela::desenha(){
    //cachorro
    if (selecionado) {
        glColor3d(0,1,0);

    } else {
        glColor3d(0,0,1);
    }
    glPushMatrix();
    Objeto::desenha();
//        glTranslatef(0.0,0.0,0.0);
        glTranslatef(0.5,0.2,1.4);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.001,-0.0003,-0.00026);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();

    glPushMatrix();
    Objeto::desenha();
//        glTranslatef(0.0,0.0,0.0);
        glTranslatef(-0.4,0.2,0.4);
        glRotated(90,1,0,0);
        glScalef(-0.001,-0.0003,-0.00026);
        malha->draw();
        // Brilho do material
        especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
