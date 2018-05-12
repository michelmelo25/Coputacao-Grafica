#ifndef SEMAFORO_H
#define SEMAFORO_H
#include "objeto.h"
#include "Desenha.h"
//Traffic light.3DS
class Semaforo: public Objeto
{
public:
    Semaforo();
    void desenha();
};

#endif // SEMAFORO_H
