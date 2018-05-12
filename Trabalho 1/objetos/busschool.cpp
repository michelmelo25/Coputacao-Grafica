#include "obj/busschool.h"
//Bus School.3DS
BusSchool::BusSchool(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Bus School.3DS");
}

void BusSchool::desenha(){
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,0,1);
    }
    glPushMatrix();
    Objeto::desenha();
        glTranslatef(-3.0,0.0,4.5);
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
