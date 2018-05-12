#include "obj/porta.h"

Porta::Porta(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Door 1.3ds");
}

void Porta::desenha(){
    //cachorro
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0.5,0.3,0.8);
    }
    glPushMatrix();
//        glTranslatef(0,0,0);
        glTranslatef(0.3,-0.72,0.999);
        glTranslatef(0.5,1.0,0);
        glRotatef(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(-0.001,-0.0003,-0.00026);
        malha->draw();
    glPopMatrix();
}
