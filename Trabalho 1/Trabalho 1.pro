TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += user

LIBS += -lGL -lGLU -lglut -l3ds -lSDL -lSDL_image
#LIBS += -lglut -lgsl -l3ds -lGLU -lGL -lm -lSDL -lSDL_image

#INCLUDE_PATH += bib

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/Vetor3D.cpp \
    bib/model3ds.cpp \
    objetos/objeto.cpp \
    objetos/casa.cpp \
    objetos/lobo.cpp \
    objetos/estrada.cpp \
    objetos/porta.cpp \
    objetos/janela.cpp \
    objetos/busstop.cpp \
    objetos/chao.cpp \
    objetos/semaforo.cpp \
    objetos/busschool.cpp \
    objetos/grass.cpp \
    objetos/bush.cpp \
    objetos/gate.cpp \
    objetos/fence.cpp \
    objetos/arvore.cpp \
    objetos/garagem.cpp \
    objetos/carro.cpp \
    objetos/caminho.cpp


HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/Vetor3D.h \
    bib/model3ds.h \
    obj/objeto.h \
    obj/casa.h \
    obj/lobo.h \
    obj/estrada.h \
    obj/porta.h \
    obj/janela.h \
    obj/busstop.h \
    obj/chao.h \
    obj/semaforo.h \
    obj/busschool.h \
    obj/grass.h \
    obj/bush.h \
    obj/gate.h \
    obj/fence.h \
    obj/arvore.h \
    obj/garagem.h \
    obj/carro.h \
    obj/caminho.h

