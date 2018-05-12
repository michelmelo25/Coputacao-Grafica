#include "obj/busstop.h"

BusStop::BusStop(){
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Bus stop.3DS");
}

void BusStop::desenha(){
    //cachorro
    if (selecionado) {
        glColor3d(0,1,0);
    } else {
        glColor3d(0,0,1);
    }
    glPushMatrix();
    Objeto::desenha();
//        glTranslatef(0.3,-0.72,0.999);
        glTranslatef(-3.0,0.0,3.8);
//        glRotatef(90,0,1,0);
        glRotated(90,1,0,0);
        glScalef(-0.001,-0.0003,-0.00026);
        malha->draw();
        // Brilho do material
        int especMaterial = 60;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
