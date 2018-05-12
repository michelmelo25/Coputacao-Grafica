#ifndef CAMINHO_H
#define CAMINHO_H
#include "objeto.h"
#include "Desenha.h"

class Caminho: public Objeto
{
public:
    Caminho();
    void caminho();
    void desenha();

private:
    GLfloat xmin;
    GLfloat ymin;
    GLfloat zmin;
    GLfloat xmax;
    GLfloat ymax;
    GLfloat zmax;
};

#endif // CAMINHO_H
