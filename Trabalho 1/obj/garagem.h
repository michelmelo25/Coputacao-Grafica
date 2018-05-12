#ifndef GARAGEM_H
#define GARAGEM_H
#include "objeto.h"
#include "Desenha.h"

class Garagem: public Objeto
{
public:
    Garagem();
    void garagem();
    void desenha();

private:
    GLfloat xmin;
    GLfloat ymin;
    GLfloat zmin;
    GLfloat xmax;
    GLfloat ymax;
    GLfloat zmax;
};

#endif // GARAGEM_H
