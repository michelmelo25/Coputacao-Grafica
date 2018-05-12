#include "obj/objeto.h"
#include "lobo.h"

Objeto::Objeto()
{
//    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/wolf.3ds");
    ///home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds
}

void Objeto::desenha()
{
//    glPushMatrix();
        //composicao de transformacoes
        glTranslated(tx,ty,tz);
        glRotated(az,0,0,1);
        glRotated(ay,0,1,0);
        glRotated(ax,1,0,0);
        glScaled(sx,sy,sz);

        //desenhando objeto

        //casa
//        if (selecionado) {
//            glColor3d(0,1,0);
//        } else {
//            glColor3d(1,0,0);
//        }
//        glPushMatrix();
//            casa(0.0,0.0,0.0, 1.0,1.0,1.0);
//        glPopMatrix();

//        //caixa
//        if (selecionado) {
//            glColor3d(0,1,0);
//        } else {
//            glColor3d(1,1,0);
//        }
//        glPushMatrix();
//            glTranslatef(0.5,0.0,0.0);
//            Desenha::drawBox( 0.2,0.0,0.2, 0.4,0.2,0.4 );
//        glPopMatrix();

        //cachorro
//        if (selecionado) {
//            glColor3d(0,1,0);
//        } else {
//            glColor3d(0,0,1);
//        }
//        glPushMatrix();
//            glTranslatef(0.5,0.0,0.5);
//            glRotated(-90,1,0,0);
//            glScalef(0.5,0.5,0.5);
//            malha->draw();
//        glPopMatrix();
//    glPopMatrix();
}

