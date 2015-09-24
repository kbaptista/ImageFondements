#include <GL/glut.h>    // GLUT Library 
#include <GL/gl.h>	// OpenGL32 Library
#include <GL/glu.h>	// GLu32 Library
#include "stdio.h"
#include <math.h>

int window; 

/* angle de rotation pour notre carre */
float rcx = 0.0f;
float rcy = 0.0f;

/* Variables de Camera */
//Coordonnés de la caméra
float x = 0.0f;
float z = 5.0f;
//Direction de la caméra
float lx = 0.0f;
float ly = 0.0f;
float lz = -1.0f;
//angle de la camera
float anglex = 0.0f;
float angley = 0.0f;
//changement d'angle de la camera
float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;
int xOrigin = -1;
int yOrigin = -1;



void translate(GLfloat * vertices, int vertices_length, GLfloat * move ); 
void mouse(int button,int state,int x,int y) { //détecte qu'un bouton est appuyé

  if (button == GLUT_LEFT_BUTTON) {

    if (state == GLUT_UP) {
      anglex += deltaAnglex;
      angley += deltaAngley;
      xOrigin = -1;
      yOrigin = -1;
    }
    else  {
      xOrigin = x;
      yOrigin = y;
    }
  }
}

void mousemotion(int x,int y){ //calcul et applique le déplacement (x et y sont les positions de la souris dans la fenêtre au moment de l'appel de la fonction.)
  if (xOrigin >= 0) {
    deltaAnglex = (x- xOrigin)*0.001f;
/*
    lx = -sin(anglex + deltaAnglex);
    lz = -cos(anglex + deltaAnglex);*/
    
  }
  if (yOrigin >=0) {

    deltaAngley = (y - yOrigin)*0.001f;
    /*
    ly = sin(angley + deltaAngley);
    lz = -cos(angley + deltaAngley);*/

  }
}



void keyboard(unsigned char touche,int x,int y) {
  switch (touche){
    case 'q' :
    case 'Q' :
    case 27  : // Touche ESC
      exit (0);
      break;
  }
}

/* fonction d'initialisation */
void InitGL(int Width, int Height)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// Fond noir
  glClearDepth(1.0);				// on vide le z-buffer 
  glDepthFunc(GL_LESS);				// on définit le type de test
  glEnable(GL_DEPTH_TEST);			// on permet les tests en question
  glShadeModel(GL_SMOOTH);			// Smooth Color Shading

  glMatrixMode(GL_PROJECTION);                  // mode 'projection'
  glLoadIdentity();				// on initialise avec la matrice identité
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// calcul de l'aspect ratio de la fenêtre 

  glMatrixMode(GL_MODELVIEW); // on passe en mode 'vue'
}

/* en cas de redimensionnement */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// au cas où
    Height=1;

  glViewport(0, 0, Width, Height);		// on utilise toute la fenêtre

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f); // aspect ratio
  glMatrixMode(GL_MODELVIEW); 
}

/* dessin de la scène */
void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// on vide les buffers 
  glLoadIdentity();				// on initialise avec la matrice identité

  float cosx = cos(anglex) ;
  float cosy = cos(angley) ;
  float sinx = sin(anglex) ;
  float siny = sin(angley) ;

  glMatrixMode(GL_MODELVIEW);
  float cameracoord [] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,    z,
    0.0f, 0.0f, 0.0f, 1.0f,
  };
  float comeback [] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,   -z,
    0.0f, 0.0f, 0.0f, 1.0f,
  };
  float rotationY [] = {
    cosx, 0.0f, sinx, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    -sinx, 0.0f, cosx, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
  };
  float rotationX [] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, cosy, -siny, 0.0f,
    0.0f, siny, cosy, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
  };

  glMultMatrixf(cameracoord);
  glMultMatrixf(rotationY);
  glMultMatrixf(rotationX);
  /*
  glRotatef(anglex+deltaAnglex, lx, ly, lz);
  glRotatef(angley+deltaAngley, lx, ly, lz);*/
  glMultMatrixf(comeback);

  // Set the camera
/*  gluLookAt(  x, 1.0f, z,
            x+lx, 1.0f+ly,  z+lz,
            0.0f, 1.0f,  0.0f);
*/
  glTranslatef(0.0f,0.0f,-10.0f);		// on translate la scène vers le fond
	
  glRotatef(rcy,0.0f,1.0f,0.0f);		// on fait tourner la scène sur l'axe des Y
  glRotatef(rcx,1.0f,0.0f,0.0f);		// on fait tourner la scène sur l'axe des X

  GLfloat square_vertices [] = {
    -1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,
     1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
     1.0f, 1.0f,-1.0f,
     1.0f,-1.0f,-1.0f,
  };

  GLubyte square_indices [] = {
    0,1,2,3,
    0,3,4,5,
    5,6,7,4,
    6,7,2,1,
    0,1,6,5,
    2,3,4,7,
  };

  GLfloat triangle_vertices [] = {
     0.0f, 1.0f, 0.0f,
    -0.6f,-1.0f, 0.6f,
     0.6f,-1.0f, 0.6f,
     0.0f,-1.0f,-0.6f,
  };

  GLubyte triangle_indices [] = {
    0,1,2,
    0,1,2,
    0,2,3,
    1,2,3,
  };

  GLfloat colors [] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f,
    1.0f, 0.5f, 0.0f,
    0.5f, 0.0f, 1.0f,
  };

  GLfloat move_square [] = {-2.0f, -2.0f, .0f};
  GLfloat move_triangle [] = {2.0f, -2.0f, .0f};
  
    
  translate(square_vertices, 24, move_square);
  translate(triangle_vertices, 12, move_triangle);

  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);

  glColorPointer(3, GL_FLOAT, 0, colors);
  glVertexPointer(3, GL_FLOAT, 0, square_vertices);
  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, square_indices);

  glColorPointer(3, GL_FLOAT, 0, colors);
  glVertexPointer(3, GL_FLOAT, 0, triangle_vertices);
  glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, triangle_indices);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

/*
  glColor3f ( 1.0f, 1.0f, 1.0f);
*/
  glEnd();
 
  glLoadIdentity();				// on ré initialise le point de vue de la scène
	
  //rcx += 0.5f;					// Augmente la variable pour la rotation du carre sur l'axe des x
  //rcy += 0.25f;					// Augmente la variable pour la rotation du carre sur l'axe des y

  // on échange les buffers (double buffering)
  glutSwapBuffers();
}

void translate(GLfloat vertices[], int vertices_length, GLfloat move[]){
  int cpt = 0;
  for (int i = 0; i < vertices_length; ++i)
  {
    vertices[i]+=move[cpt];
    cpt++;
    if (cpt == 3)
    {
      cpt=0;
    }
  }
}

int main(int argc, char **argv) 
{ 

  int width = 640;
  int height = 480;
  /* initialisation de glut */
  glutInit(&argc, argv);  

  /* Mode d'affichage
     RGBA color
     Double buffer      
     Alpha components supported 
     z-buffer */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* taille de la fenêtre 640 x 480 */
  glutInitWindowSize(width, height);  

  /* la fenêtre se positionne en haut à gauche */
  glutInitWindowPosition(0, 0);  

  /* on crée la fenêtre */  
  window = glutCreateWindow("Fortement inspire par les Tutoriaux NeHe - exo1");  

  /* On 'register' la fonction de dessin */
  glutDisplayFunc(&DrawGLScene);  

  /* fullscreen */
  /* glutFullScreen(); */

  /* même sans événements, on va re dessiné la scène */
  glutIdleFunc(&DrawGLScene);

  /* les autres fonctions, gérant les événements :
     claviers => glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
     souris => glutMouseFunc(void (*func)(int button, int state, int x, int y)); 
     mouvement de la sourie => void glutMotionFunc(void (*fonct)(int x,int y));
  */

  glutKeyboardFunc(keyboard); 
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);

  /* en cas de redimensionnement */
  glutReshapeFunc(&ReSizeGLScene);
  

  /* on initialise la scène */
  InitGL(width, height);
  
  /* On lance la boucle de la gestion d'événements */  
  glutMainLoop();

  return 1;
}
