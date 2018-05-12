#include "obj/casa.h"
#include "obj/porta.h"
#include "obj/janela.h"

Casa::Casa(GLfloat xmin, GLfloat ymin, GLfloat zmin, GLfloat xmax, GLfloat ymax, GLfloat zmax){
    this->xmin = xmin;
    this->ymin = ymin;
    this->zmin = zmin;
    this->xmax = xmax;
    this->ymax = ymax;
    this->zmax = zmax;
    malha = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Door 1.3ds");
    this->malha2 = new Model3DS("/home/michel/Documentos/UFC/5 Semestre/CG/Trabalho 1/run/3ds/Window 1.3DS");

    porta = new Porta();
    janela = new Janela();

}
//GLfloat xmin, GLfloat ymin, GLfloat zmin, GLfloat xmax, GLfloat ymax, GLfloat zmax
void Casa::casa(){
        glEnable(GL_CULL_FACE);
glPushMatrix();
        Objeto::desenha();
        glTranslated(0,0,-1);
        //Frente
        glPushMatrix();
        glTranslatef(0,0,1);
            glBegin(GL_QUADS);
              glNormal3f(0.,0.,1.);
              glVertex3f(xmax, ymin, zmin);
              glVertex3f(xmax, ymax, zmin);
              glVertex3f(xmin, ymax, zmin);
              glVertex3f(xmin, ymin, zmin);
            glEnd();
        glPopMatrix();

        //Lateral Esquerdo
        glPushMatrix();
        glTranslatef(-1,0,0);
            glBegin(GL_QUADS);
              glNormal3f(-1.,0.,0.);
              glVertex3f(xmax, ymin, zmax);
              glVertex3f(xmax, ymax, zmax);
              glVertex3f(xmax, ymax, zmin-1);
              glVertex3f(xmax, ymin, zmin-1);
            glEnd();
        glPopMatrix();

        //Fundo
        glPushMatrix();
        glTranslatef(0,0,-2);
            glBegin(GL_QUADS);
              glNormal3f(0.,0.,-1.);
              glVertex3f(xmin, ymin, zmax);
              glVertex3f(xmin, ymax, zmax);
              glVertex3f(xmax, ymax, zmax);
              glVertex3f(xmax, ymin, zmax);
            glEnd();
        glPopMatrix();

        //Lateral Direita
        glPushMatrix();
        glTranslatef(1,0,0);
            glBegin(GL_QUADS);
              glNormal3f(1.,0.,0.);
              glVertex3f(xmin, ymin, zmin-1);
              glVertex3f(xmin, ymax, zmin-1);
              glVertex3f(xmin, ymax, zmax);
              glVertex3f(xmin, ymin, zmax);
            glEnd();
        glPopMatrix();

        //chao
        glPushMatrix();
        glTranslatef(0,-1,0);
            glBegin(GL_QUADS);
              glNormal3f(0.,-1.,0.);
              glVertex3f(xmax, ymax, zmin-1);
              glVertex3f(xmax, ymax, zmax);
              glVertex3f(xmin, ymax, zmax);
              glVertex3f(xmin, ymax, zmin-1);
            glEnd();
        glPopMatrix();

        //Teto
        glPushMatrix();
        glTranslatef(0,1,0);
            glBegin(GL_QUADS);
              glNormal3f(0.,1.,0.);
              glVertex3f(xmin, ymin, zmin-1);
              glVertex3f(xmin, ymin, zmax);
              glVertex3f(xmax, ymin, zmax);
              glVertex3f(xmax, ymin, zmin-1);
            glEnd();
        glPopMatrix();

            //Telhado diagonal direito
        glPushMatrix();
        if (selecionado) {
            glColor3d(0,1,0);
        } else {
            glColor3d(0.92,0.51,0.23);
        }

            glTranslatef( (xmax-xmin),(ymax-ymin),0.0 );
            glRotatef(-30,0,0,1);
            glTranslatef( -(xmax-xmin)/2,-(ymax-ymin),0.0 );
            glBegin(GL_QUADS);
              glNormal3f(0.,1.,0.);
              glVertex3f(xmin-0.089, ymax, zmin-1);
              glVertex3f(xmin-0.089, ymax, zmax);
              glVertex3f(xmax-0.5, ymax, zmax);
              glVertex3f(xmax-0.5, ymax, zmin-1);
            glEnd();
        glPopMatrix();

            //Telhado diagonal esquerdo
        glPushMatrix();
        if (selecionado) {
            glColor3d(0,1,0);
        } else {
            glColor3d(0.92,0.51,0.23);
        }
            glTranslatef( 0,(ymax+ymin),0.0 );
            glRotatef(30,0,0,1);
            glTranslatef( -(xmax-xmin)/2,-(ymax-ymin),0.0 );
            glBegin(GL_QUADS);
              glNormal3f(0.,1.,0.);
              glVertex3f(xmin+0.5, ymax, zmin-1);
              glVertex3f(xmin+0.5, ymax, zmax);
              glVertex3f(xmax+0.089, ymax, zmax);
              glVertex3f(xmax+0.089, ymax, zmin-1);
            glEnd();
        glPopMatrix();

        //Teto lateral frente
        glPushMatrix();
        if (selecionado) {
            glColor3d(0,1,0);
        } else {
            glColor3d(0.92,0.51,0.23);
        }
            glTranslatef(0,0,1);
            glTranslatef(0,0.3,0);
                glBegin(GL_QUADS);
                  glNormal3f(0.,0.,1.);
                  glVertex3f(xmax, ymin+0.7, zmin);
                  glVertex3f(xmax, ymax-0.3, zmin);
                  glVertex3f(xmin+0.5, ymax, zmin);
                  glVertex3f(xmin, ymin+0.7, zmin);
                glEnd();
        glPopMatrix();

        glPushMatrix();
        if (selecionado) {
            glColor3d(0,1,0);
        } else {
            glColor3d(0.92,0.51,0.23);
        }
            glTranslatef(0,0,1);
            glTranslatef(0,0.3,0);
                glBegin(GL_QUADS);
                  glNormal3f(0.,0.,1.);
                  glVertex3f(xmax, ymin+0.7, zmin);
                  glVertex3f(xmax-0.5, ymax, zmin);
                  glVertex3f(xmin, ymax-0.3, zmin);
                  glVertex3f(xmin, ymin+0.7, zmin);
                glEnd();
        glPopMatrix();

        //Teto lateral fundo
        glPushMatrix();
        if (selecionado) {
            glColor3d(0,1,0);
        } else {
            glColor3d(0.92,0.51,0.23);
        }
            glTranslatef(0,0,-1);
            glTranslatef(0,0.3,0);
                glBegin(GL_QUADS);
                  glNormal3f(0.,0.,-1.);
                  glVertex3f(xmin, ymin+0.7, zmax-1);
                  glVertex3f(xmin+0.5, ymax, zmax-1);
                  glVertex3f(xmax, ymax-0.3, zmax-1);
                  glVertex3f(xmax, ymin+0.7, zmax-1);
                glEnd();
        glPopMatrix();

        glPushMatrix();
        if (selecionado) {
            glColor3d(0,1,0);
        } else {
            glColor3d(0.92,0.51,0.23);
        }
            glTranslatef(0,0,-1);
            glTranslatef(0,0.3,0);
                glBegin(GL_QUADS);
                  glNormal3f(0.,0.,-1.);
                  glVertex3f(xmin, ymin+0.7, zmax-1);
                  glVertex3f(xmin, ymax-0.3, zmax-1);
                  glVertex3f(xmax-0.5, ymax, zmax-1);
                  glVertex3f(xmax, ymin+0.7, zmax-1);
                glEnd();
        glPopMatrix();

        //Porta
        porta->desenha();

        //Janela
        janela->desenha();
        glPopMatrix();
}

void Casa::desenha()
{
        //desenhando objeto

        //casa
        if (selecionado) {
            glColor3d(0,1,0);
            porta->selecionado = true;
            janela->selecionado = true;
        } else {
            glColor3d(1,0,0);
            porta->selecionado = false;
            janela->selecionado = false;
        }
        glPushMatrix();
            casa();
//            0.0,0.0,0.0, 1.0,1.0,1.0
        glPopMatrix();
}
