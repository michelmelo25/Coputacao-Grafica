#ifndef OBJETO_H
#define OBJETO_H

#include <bib/model3ds.h>
#include <bib/Desenha.h>

class Objeto
{
public:


    float tx = 0.0;
    float ty = 0.0;
    float tz = 0.0;

    float ax = 0.0;
    float ay = 0.0;
    float az = 0.0;

    float sx = 1.0;
    float sy = 1.0;
    float sz = 1.0;

    bool selecionado = false;

    Model3DS* malha;

    Objeto();

    void personagem();
    //void casa(GLfloat xmin, GLfloat ymin, GLfloat zmin, GLfloat xmax, GLfloat ymax, GLfloat zmax);
    virtual void desenha();
};

#endif // OBJETO_H
