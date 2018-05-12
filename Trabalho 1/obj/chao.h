#ifndef CHAO_H
#define CHAO_H
#include "objeto.h"
#include "Desenha.h"

class Chao: public Objeto
{
public:
    Chao();
    void chao();
    void desenha();

private:
    GLfloat xmin;
    GLfloat ymin;
    GLfloat zmin;
    GLfloat xmax;
    GLfloat ymax;
    GLfloat zmax;
};

#endif // CHAO_H
