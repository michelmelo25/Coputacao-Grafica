#ifndef JANELA_H
#define JANELA_H
#include "objeto.h"
#include "Desenha.h"

class Janela: public Objeto
{
public:
    Janela();
    void desenha();
};

#endif // JANELA_H
