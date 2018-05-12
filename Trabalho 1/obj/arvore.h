#ifndef ARVORE_H
#define ARVORE_H
#include "objeto.h"
#include "Desenha.h"

class Arvore: public Objeto
{
public:
    Arvore();
    void desenha();

private:
    Model3DS* malha2;
};

#endif // ARVORE_H
