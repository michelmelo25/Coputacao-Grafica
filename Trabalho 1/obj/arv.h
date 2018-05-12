#ifndef ARV_H
#define ARV_H
#include "objeto.h"
#include "Desenha.h"

class Arv: public Objeto
{
private:
    GLUquadric *quad;
    int numberCups;
    GLdouble slices;
    GLdouble stacks;
public:
    Arv(GLUquadric *quad, int numberCups, GLdouble slices, GLdouble stacks);
    void desenha();
};

#endif // ARV_H
