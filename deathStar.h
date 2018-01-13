#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include <GL/glut.h>

#define SENS_ROT 5.0
#define SENS_OBS 20.0
#define SENS_TRANSL 30.0


void display();
void reshape(GLsizei w,GLsizei h);
void projecao();
void keyboard(unsigned char tecla, int x, int y);
void desenhaEixos();
void mouse(int button, int state, int x, int y);   
void motion(int x, int y);
void timer(int t);
void inicializa();
void material();

#endif