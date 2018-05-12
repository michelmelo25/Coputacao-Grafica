#include "obj/semaforo.h"

Semaforo::Semaforo(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Traffic light.3DS");
}

void Semaforo::desenha(){
    //cachorro
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,0,1);
    }
    glPushMatrix();
    Objeto::desenha();
        glTranslatef(-4.9,0.0,0.0);
        glTranslatef(0.0,0.0,3.8);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.0004,-0.0001,-0.00009);

        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
