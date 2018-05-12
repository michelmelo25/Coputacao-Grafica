#include "obj/grass.h"
//Grass in box.3DS
Grass::Grass(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Grass in box.3DS");

}

void Grass::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,1,1);
    }
    glPushMatrix();
    Objeto::desenha();
        glTranslatef(0.0,0.0,-1.0);
        glTranslatef(0.3,-1.93,1.2);
        glTranslatef(0.0,2.1,0.0);
        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.002,-0.002,-0.0015);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
