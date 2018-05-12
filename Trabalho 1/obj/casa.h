#ifndef CASA_H
#define CASA_H
#include "objeto.h"
#include "porta.h"
#include "janela.h"
#include "Desenha.h"

class Casa: public Objeto
{
public:
    Casa(GLfloat xmin, GLfloat ymin, GLfloat zmin, GLfloat xmax, GLfloat ymax, GLfloat zmax);
    void casa();
//    GLfloat xmin, GLfloat ymin, GLfloat zmin, GLfloat xmax, GLfloat ymax, GLfloat zmax
    void desenha();
    //algo para salvar
private:
    GLfloat xmin;
    GLfloat ymin;
    GLfloat zmin;
    GLfloat xmax;
    GLfloat ymax;
    GLfloat zmax;
    Porta * porta;
    Janela * janela;

    Model3DS * malha2;
};

#endif // CASA_H
