#include "obj/arvore.h"

Arvore::Arvore(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Tree oak.3ds");
    malha2 = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Tree2.3DS");
}

void Arvore::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,1,1);
    }
    glPushMatrix();
    Objeto::desenha();
//        glTranslatef(0.3,-0.72,0.999);
        glTranslatef(2.3,0.85,0.0);
//        glRotatef(-90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.0004,-0.0004,-0.0002);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
