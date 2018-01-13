#include "deathStar.h"


bool orto = false;
float win = 10.0f;
float aspecto = 1.0;
float angulo = 60.0f;
int objeto = 0;
bool eixos = true;
bool wire = true;
float passoLento = 0.003;
float passoMuitoLento = 0.001;
float passoRapido = 0.009;
float x = -15, y = 8, z = 0, w = -10, v = 8;


GLfloat rotX=0.0, rotY=0.0, rotX_ini, rotY_ini;
GLfloat obsX=0.0, obsY=0.0, obsZ=15.0, obsX_ini, obsY_ini,obsZ_ini;
int x_ini, y_ini, bot;


void inicializa(){
  GLfloat ambient[] = {0.2,0.2,0.2,0.2};
  GLfloat difusa[] = {1.0,1.0,1.0,0.2};
  GLfloat posicao[] = {-15,8,0,0.8};
  GLfloat especular[] = {0,0,0,0.4};
  glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
  glEnable(GL_LIGHTING);
  glEnable( GL_COLOR_MATERIAL );
  glEnable(GL_DEPTH_TEST); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa);
  //glLightfv(GL_LIGHT0, GL_POSITION, posicao);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_SPECULAR, especular);
  glEnable(GL_NORMALIZE);
  glShadeModel(GL_FLAT);
  material();
}


void material(){
  GLfloat matDifusa[] = {0.0,0.0,0.0,1.0};
  GLfloat matEspecular[] = {0.0,0.0,0.0,1.0};
  GLfloat matBrilho[] = {1.0};
  glMaterialfv(GL_FRONT, GL_DIFFUSE, matDifusa);
  glMaterialfv(GL_FRONT, GL_AMBIENT, matDifusa);
  glMaterialfv(GL_FRONT, GL_SPECULAR, matEspecular);
  glMaterialfv(GL_FRONT, GL_SHININESS, matBrilho);
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //if(eixos){
  //  desenhaEixos();
  //} 


  //Death Star
  glPushMatrix();
    glTranslatef(10,0,0);

    glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(0,0,0);
    glScalef(1,1,1);
    glutWireSphere(5,250,250);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.1);
    glTranslatef(0,0,0);
    glScalef(1,1,1);
    glutWireSphere(4.9,200,200);
    glPopMatrix();
  glPopMatrix();


  //Endor
  glPushMatrix();
    glTranslatef(-50,-50,-100);
    
    //Corpo
    glPushMatrix();
    glColor3f(0.1,0.1,0.3);
    glTranslatef(0,0,0);
    glScalef(1,1,1);
    glutSolidSphere(30,60,60);
    glPopMatrix();
  glPopMatrix();


  //Lua Endor
  glPushMatrix();
    glTranslatef(0,0,-30);

    //Anel
    glPushMatrix();
    glColor3f(0.6,0.5,0.2);
    glRotatef(0.8,0.5,0.2,0.4);
    //glTranslatef(0,0,0);
    glScalef(1,1,1);
    glutSolidTorus(0.1,10,60,60);
    glPopMatrix();
    
    //Corpo
    glPushMatrix();
    glColor3f(0.6,0.8,0);
    glTranslatef(0,0,0);
    glScalef(1,1,1);
    glutSolidSphere(6,60,60);
    glPopMatrix();
  glPopMatrix();


  //Nave Rebelde
  glPushMatrix();
    glTranslatef(x,y,z);

    //Corpo
    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glScalef(0.5,0.5,4);
    glTranslatef(0,0,0);
    glutSolidCube(1);
    glPopMatrix();

    //Hangar
    glPushMatrix();
    glColor3f(1,0,0);
    glScalef(1,0.25,2);
    glTranslatef(0,0,0);
    glutSolidCube(1);
    glPopMatrix();

    //Passadiço
    glPushMatrix();
    glColor3f(1,0,0);
    glScalef(1.2,1,1);
    glTranslatef(0,0.3,1.8);
    glutSolidCube(0.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glScalef(2,1,1);
    glTranslatef(0,0.5,1.8);
    glutSolidCube(0.3);
    glPopMatrix();
  glPopMatrix();

  //Caça Imperial
  for(float j=6;j<10;j=j+2){
    for(float i=0;i>-8;i=i-2){
      glPushMatrix();
        glColor3f(0,0,1);
        glTranslatef(j,v,i);
        

        //Corpo
        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,1,1);
        glTranslatef(0,0,0);
        glutSolidSphere(0.2,10,10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.7,0.7,0.7);
        glScalef(0.01,0.01,1.5);
        glTranslatef(0,0,0);
        glutSolidCube(0.6);
        glPopMatrix();

        //Asas
        glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glScalef(1,1,0.01);
        glTranslatef(0,0,30);
        glutSolidCube(0.6);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glScalef(1,1,0.01);
        glTranslatef(0,0,-30);
        glutSolidCube(0.6);
        glPopMatrix();
      glPopMatrix();
    }
  }

  //Caça Rebelde
  for(int i=-10;i<-2;i=i+2){
    glPushMatrix();
      glTranslatef(w,8,i);
      

      //Corpo
      glPushMatrix();
      glColor3f(1,0,0);
      glScalef(3,0.4,0.4);
      glTranslatef(0,0,0);
      glutSolidCube(0.3);
      glPopMatrix();

      glPushMatrix();
      glColor3f(1,1,1);
      glScalef(0.01,0.01,0.8);
      glTranslatef(-38,0,0);
      glutSolidCube(0.5);
      glPopMatrix();

      //Asas
      glPushMatrix();
      glColor3f(1,1,1);
      glScalef(1,0.3,0.2);
      glTranslatef(-0.3,0,1);
      glutSolidCube(0.3);
      glPopMatrix();

      glPushMatrix();
      glColor3f(1,1,1);
      glScalef(1,0.3,0.2);
      glTranslatef(-0.3,0,-1);
      glutSolidCube(0.3);
      glPopMatrix();
    glPopMatrix();
  }

  //Caça Rebelde 2
  for(int i=0;i<8;i=i+2){
    glPushMatrix();
      glTranslatef(w,6,i);
      

      //Corpo
      glPushMatrix();
      glColor3f(1,0,0);
      glScalef(3,0.4,0.4);
      glTranslatef(0,0,0);
      glutSolidCube(0.3);
      glPopMatrix();

      glPushMatrix();
      glColor3f(1,1,1);
      glScalef(0.01,0.01,0.8);
      glTranslatef(-38,0,0);
      glutSolidCube(0.5);
      glPopMatrix();

      //Asas
      glPushMatrix();
      glColor3f(1,1,1);
      glScalef(1,0.3,0.2);
      glTranslatef(-0.3,0,1);
      glutSolidCube(0.3);
      glPopMatrix();

      glPushMatrix();
      glColor3f(1,1,1);
      glScalef(1,0.3,0.2);
      glTranslatef(-0.3,0,-1);
      glutSolidCube(0.3);
      glPopMatrix();
    glPopMatrix();
  }


  //formas();
  glutSwapBuffers();
}


//if(mat) material();
//else glColor3f(...);
//desenha();


void reshape(GLsizei w, GLsizei h){
  if(h == 0) h = 1;
  glViewport(0, 0, w, h);
  aspecto = (float) w/h;
  projecao();
}


void projecao(){   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  if(orto){
    glOrtho(-win*aspecto, win*aspecto, -win, win, -win, win);
  } else {
    gluPerspective(angulo, aspecto, 0.1f, 1000.0f);
  }
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(obsX,obsY,obsZ,0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
}


void keyboard( unsigned char tecla, int x, int y ){

  switch (tecla){
    case 27: exit(0); break;
    //case 'a': eixos = !eixos; break;
    case 'p': orto = false ; projecao(); break;
    case 'o': orto = true; projecao(); break; 
    //case 'w': wire =! wire; break; 
    //case 's':
  }

  glutPostRedisplay();
}


void desenhaEixos(){
  glLineWidth(2.0f);

  glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glColor3f (0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2.0f);
  glEnd();
}


void mouse(int button,int state,int x,int y){
  if( state == GLUT_DOWN ) {
    x_ini = x;
    y_ini = y;
    obsX_ini = obsX;
    obsY_ini = obsY;
    obsZ_ini = obsZ;
    rotX_ini = rotX;
    rotY_ini = rotY;
    bot = button;
  }else{
    bot = -1;
  }
}


void timer (int t){
  //x = x - passo;
  y = y - passoLento;
  z = z - passoLento;
  w = w + passoRapido;
  v = v - passoMuitoLento;

  glutPostRedisplay();

  glutTimerFunc(10,timer,1);
}


void motion(int x,int y) {
  
  if( bot == GLUT_LEFT_BUTTON ){
    int deltax = x_ini - x;
    int deltay = y_ini - y;
    rotY = rotY_ini - deltax/SENS_ROT;
    rotX = rotX_ini - deltay/SENS_ROT;
  }else if( bot == GLUT_RIGHT_BUTTON ){
    int deltaz = y_ini - y;
    obsZ = obsZ_ini + deltaz/SENS_OBS;
  }else if( bot == GLUT_MIDDLE_BUTTON ){
    int deltax = x_ini - x;
    int deltay = y_ini - y;
    obsX = obsX_ini + deltax/SENS_TRANSL;
    obsY = obsY_ini - deltay/SENS_TRANSL;
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(-obsX, -obsY, -obsZ);
  glRotatef(rotX,1,0,0);
  glRotatef(rotY,0,1,0);
  glutPostRedisplay();
}