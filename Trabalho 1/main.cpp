#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>
#include <vector>
#include <bib/model3ds.h>
//Objetos
#include "obj/objeto.h"
#include "obj/casa.h"
#include "obj/lobo.h"
#include "obj/estrada.h"
#include "obj/porta.h"
#include "obj/janela.h"
#include "obj/busstop.h"
#include "obj/chao.h"
#include "obj/semaforo.h"
#include "obj/busschool.h"
#include "obj/grass.h"
#include "obj/bush.h"
#include "obj/gate.h"
#include "obj/fence.h"
#include "obj/arvore.h"
#include "obj/garagem.h"
#include "obj/carro.h"
#include "obj/caminho.h"


/*
MICHEL DE MELO VIEIRA
389959
CIENCIA DA COMPUTAÇÃO
*/

using namespace std;

//Model3DS* malha = new Model3DS("3ds/wolf.3ds");

vector<Objeto*> objetos;
vector<Objeto*> psobjetos;

int selecionado = -1;

int iterador = 0;

float width = 800;
float height = 600;

float trans_obj = false;

float tx = 0.0;
float ty = 0.0;
float tz = 0.0;

float ax = 0.0;
float ay = 0.0;
float az = 0.0;

//float delta = 5.0;

float sx = 1.0;
float sy = 1.0;
float sz = 1.0;

float slices = 20;
float stacks = 20;

bool lbpressed = false;
bool mbpressed = false;
bool rbpressed = false;

float last_x = 0.0;
float last_y = 0.0;

Camera* cam = new CameraDistante();
Camera* cam2 = new CameraDistante();
//Camera* cam3 = new Camera();
float savedCamera[9];

Casa * casaM = new Casa(0,0,0,1,1,1);

Chao * chaoM = new Chao();
Estrada * estrada = new Estrada();
Caminho * caminhoM = new Caminho();

void resize(int w, int h)
{
    width = w;
    height = h;
}

void initializeGL()
{
    glClearColor(1,1,1,1);
    //glClearColor(0.3,0.3,0.3,1.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    glEnable(GL_NORMALIZE); //mantem a qualidade da iluminacao mesmo quando glScalef eh usada

    glShadeModel(GL_SMOOTH);
    //glShadeModel(GL_FLAT);

    glEnable(GL_DEPTH_TEST);

//    //definindo uma luz
        glEnable(GL_LIGHT0);

        const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
        const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

        const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat high_shininess[] = { 100.0f };

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void displayInit()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const float ar = height>0 ? (float) width / (float) height : 1.0;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.,ar,0.1,1000.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //definindo posicao e orientacao da camera
    //gluLookAt(0.0,1.0,15.0, 0.0,0.0,-1.0, 0.0,1.0,0.0);
    gluLookAt(cam->e.x,cam->e.y,cam->e.z, cam->c.x,cam->c.y,cam->c.z, cam->u.x,cam->u.y,cam->u.z);
//    gluLookAt(cam2->e.x-20,cam2->e.y+10,cam2->e.z, cam2->c.x,cam2->c.y,cam2->c.z, cam2->u.x,cam2->u.y,cam2->u.z);
}

void displayEnd()
{
    glutPostRedisplay();
    glutSwapBuffers();
}

float z = 0.0;
float r = 0.3;
float g = 0.3;
float b = 0.6;

void display(void)
{
    displayInit();

    //z += 0.001;

    //sistema global
    glPushMatrix();
        //glColor3f(1.0,0,0);
        //glBegin(GL_QUADS);
        //    glVertex3f(0,0,z);
        //    glColor3f(0,0,1);
        //    glVertex3f(1,0,z);
        //    glColor3f(0,1,0);
        //    glVertex3f(1,1,z);
        //    glColor3f(1,1,1);
        //    glVertex3f(0,1,z);
        //glEnd();
        //desenhando eixos do sistema de coordenadas global
          Desenha::drawEixos( 0.5 );
        //chao
        //glColor3d(0.3,0.3,0.3);
        glColor3d(0.3,0.3,0.3);
        Desenha::drawGrid( 10, 0, 7, 1 );
    glPopMatrix();

     chaoM->desenha();
     estrada->desenha();
     caminhoM->desenha();
    //sistemas locais
    //desenha os objetos
    for (int i = 0; i<objetos.size(); i++) {
        objetos.at(i)->desenha();
    }

    displayEnd();
}

void mouseButton(int button, int state, int x, int y) {
    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            lbpressed = true;
        } else {// state = GLUT_UP
            lbpressed = false;
        }
    }
    // if the middle button is pressed
    if (button == GLUT_MIDDLE_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            mbpressed = true;
        } else {// state = GLUT_UP
            mbpressed = false;
        }
    }
    // if the left button is pressed
    if (button == GLUT_RIGHT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            rbpressed = true;
        } else {// state = GLUT_UP
            rbpressed = false;
        }
    }

    last_x = x;
    last_y = y;
}

void mouseMove(int x, int y) {
    float fator = 10.0;
    if (lbpressed && !rbpressed && !mbpressed) {
        if (!trans_obj) {
            cam->rotatex(y,last_y);
            cam->rotatey(x,last_x);
        } else {
            objetos.at(selecionado)->ax += (y - last_y)/fator;
            objetos.at(selecionado)->ay += (x - last_x)/fator;
        }
    }
    fator = 100.0;
    if (!lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj) {
            cam->translatex(x,last_x);
            cam->translatey(y,last_y);
        } else {
            objetos.at(selecionado)->tx += (x - last_x)/fator;
            objetos.at(selecionado)->ty += -(y - last_y)/fator;
        }
    }
    if (lbpressed && rbpressed && !mbpressed) {
        if (!trans_obj) {
            cam->zoom(y,last_y);
        } else {
            objetos.at(selecionado)->tz += (y - last_y)/fator;
            fator = 10.0;
            objetos.at(selecionado)->az += -(x - last_x)/fator;
        }
    }
    fator = 100.0;
    if (!lbpressed && !rbpressed && mbpressed) {
        if (!trans_obj) {
            r += (y - last_y)/fator;
            g += (x - last_x)/fator;
        } else {
            objetos.at(selecionado)->sx += (x - last_x)/fator;
            objetos.at(selecionado)->sy += -(y - last_y)/fator;
        }
    }
    if (lbpressed && !rbpressed && mbpressed) {
        if (!trans_obj) {
            b += (y - last_y)/fator;
        } else {
            objetos.at(selecionado)->sz += (y - last_y)/fator;
        }
    }

    last_x = x;
    last_y = y;
}


void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 : //esc
        case 13 : //enter
        case 'q':
            exit(0);
            break;

        case 'F':
            glutFullScreen();
            break;
        case 'f':
            glutReshapeWindow(800,600);
            break;

        case 'i':
            tx = 0.0;
            ty = 0.0;
            tz = 0.0;

            ax = 0.0;
            ay = 0.0;
            az = 0.0;

            sx = 1.0;
            sy = 1.0;
            sz = 1.0;
            break;

        case 'z':
            tz -= 0.1;
            break;
        case 'Z':
            tz += 0.1;
            break;

        case 'c':
//            objetos.push_back( casaM );
//            objetos.push_back( new Porta());
//            objetos.push_back( new Janela());
//            objetos.push_back(new Grass());
            r -= 0.1;
            break;

        case 'p':
//            objetos.push_back(new BusStop());
//            objetos.push_back(new BusSchool());
//            objetos.push_back(new Semaforo());
        break;

        case 'j':
//            objetos.push_back(new Bush());
//            objetos.push_back(new Gate());
//            objetos.push_back(new Fence());
        break;

        case 'C':
            r += 0.1;
            break;

        case 'r':
            ay -= 10;
            break;
        case 'R':
            ay += 10;
            break;
        case 'e':
//            objetos.push_back(new Arvore());
            break;

        case 't':
            trans_obj = !trans_obj;
            break;
        case 'b':
        if(!objetos.empty()){
            objetos.pop_back();
            iterador--;
        }
        break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
        case 'k':
//            objetos.push_back(new Garagem());
//            objetos.push_back(new Carro());
            break;
        case 'l':
//            objetos.push_back( new Lobo() );
            break;
        case 'o':
        if(iterador < psobjetos.size()){
            objetos.push_back(psobjetos[iterador]);
            iterador++;
        }
            break;
        case 'V':
            if (selecionado != -1) objetos.at(selecionado)->selecionado = false;
            selecionado++;
            selecionado = selecionado % objetos.size();
            objetos.at(selecionado)->selecionado = true;
            break;
        case 'v':
            if (selecionado != -1) objetos.at(selecionado)->selecionado = false;
            selecionado--;
            selecionado = selecionado % objetos.size();
            objetos.at(selecionado)->selecionado = true;
            break;

    }
}

void idle(void)
{
    //ty += 0.0001;
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    //chamadas de inicializacao da GLUT
        glutInit(&argc, argv);
        glutInitWindowSize(width,height);
        glutInitWindowPosition(10,10);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

        glutCreateWindow("Primeiro programa OpenGL + GLUT");

        glutReshapeFunc(resize);
        glutDisplayFunc(display);
        glutKeyboardFunc(key);
        glutIdleFunc(idle);

        glutMouseFunc(mouseButton);
        glutMotionFunc(mouseMove);

        psobjetos.push_back(casaM);
        psobjetos.push_back(new Grass());
        psobjetos.push_back(new Lobo());
        psobjetos.push_back(new Arvore());
        psobjetos.push_back(new Garagem());
        psobjetos.push_back(new Carro());
        psobjetos.push_back(new Bush());
        psobjetos.push_back(new Fence());
        psobjetos.push_back(new Gate());
        psobjetos.push_back(new Semaforo());
        psobjetos.push_back(new BusStop());
        psobjetos.push_back(new BusSchool());

    //chamadas de inicializacao da OpenGL
        initializeGL();

    //iniciando o loop principal da glut
        glutMainLoop();
}

