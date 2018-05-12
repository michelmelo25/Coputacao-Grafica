#include "obj/lobo.h"

Lobo::Lobo(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/wolf.3ds");
}

void Lobo::desenha(){
    //cachorro
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,0,1);
    }
    glPushMatrix();

        Objeto::desenha();
        glTranslatef(0.0,0.0,-1.0);
        glTranslatef(1,0.0,2);
        glRotated(-90,1,0,0);
        glScalef(0.5,0.5,0.5);
        malha->draw();
    glPopMatrix();
glPopMatrix();
}
