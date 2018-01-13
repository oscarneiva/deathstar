#include "deathStar.h"


int main( int argc, char *argv[]){
    
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
  glutInitWindowSize(500, 500);
  glutCreateWindow( "Death Star" );
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutTimerFunc(10,timer,1);

  inicializa();
  material();

  glutMainLoop();

  return 0;
}