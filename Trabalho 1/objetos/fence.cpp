#include "obj/fence.h"

Fence::Fence(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Arc.3DS");
}

void Fence::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,0,1);
    }
    glPushMatrix();
    Objeto::desenha();
//        glTranslatef(0.0,0.0,0.0);
        glTranslatef(0.3,0.0,3.0);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.007,-0.019,-0.019);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
