#include "obj/carro.h"

Carro::Carro(){
    malha =  new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Car viper.3DS");
}

void Carro::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(1,0,0);
    }
    glPushMatrix();
    Objeto::desenha();
        glTranslatef(-2.5,0.0,-0.8);
        glRotatef(-90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.0007,-0.0006,-0.0007);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
