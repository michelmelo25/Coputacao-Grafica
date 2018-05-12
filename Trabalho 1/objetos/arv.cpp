#include <iostream>
#include "arv.h"
//#include "obj/Baseobject.h"

using namespace std;

Arv::Arv(GLUquadric *quad, int numberCups, GLdouble slices, GLdouble stacks)
{
    this->quad = quad;
    this->numberCups = numberCups;
    this->slices = slices;
    this->stacks = stacks;
}

void Arv::desenha(){
    cout << "Drawing Object Tree" << endl;
    glRotated(-90,1,0,0);

    GLdouble i = 1.0; //>= 1.0 <= 2.0
    GLdouble green_base = 0.5; //Representa a relacao da largura da base e a cor

    GLfloat mult = 0.5;

    //Tronco
    glColor3d(0.6, 0.1, 0.1);
    gluCylinder(quad,
                mult*(GLdouble)numberCups/10,
                mult*(GLdouble)numberCups/10,
                (1.0), slices, stacks);



    GLfloat angle = 0.0;
    //Copas
    while (i <= numberCups) {

        glColor3d(0,green_base/i,0);

        glTranslated(0,0,1.0); //Poe uma copa sobre a outra
        gluCylinder(quad,
                    mult*((numberCups+green_base)-(i)),
                    mult*(numberCups-i),
                    (i), slices, stacks);

        i+=0.5;
    }
}
