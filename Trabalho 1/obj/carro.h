#ifndef CARRO_H
#define CARRO_H
#include "objeto.h"
#include "Desenha.h"

class Carro: public Objeto
{
public:
    Carro();
    void desenha();
};

#endif // CARRO_H
