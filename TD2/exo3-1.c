#include <GL/glut.h>    // GLUT Library 
#include <GL/gl.h>	// OpenGL32 Library
#include <GL/glu.h>	// GLu32 Library
#include "quaternion/quaternion.h"

char presse;
int anglex,angley,x,y,xold,yold;
int window; 
float rc = 0.0f;
float rotation_tete=0.0f;
float sens=1.0f;

void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
void clavier(unsigned char touche,int x,int y);

void mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    presse=0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x,int y)
  {
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
         en fonction de la position actuelle de la souris et de la derniere
         position sauvegardee */
      anglex=anglex+(x-xold); 
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }
    
    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
  }

void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'p': /* affichage du carre plein */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glutPostRedisplay();
      break;
    case 'f': /* affichage en mode fil de fer */
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glutPostRedisplay();
      break;
    case 's' : /* Affichage en mode sommets seuls */
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glutPostRedisplay();
      break;	// Enlever la face rosé pas comme le premier plan
    case 'd':
      glEnable(GL_DEPTH_TEST);
      glutPostRedisplay();
      break;
    case 'D': // Affichage la face rosé comme le premier plan
      glDisable(GL_DEPTH_TEST);
      glutPostRedisplay();
      break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
      exit(0);
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
  gluLookAt(10.0f,20.0f,20.0f,0.0f,-5.0f,0.0f,0.0f,1.0f,0.0f);
  glMatrixMode(GL_MODELVIEW); 
}

/* dessin de la scène */
void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// on vide les buffers 

  glColor3f(1.0,0.78,0.6);

  //TETE
  glLoadIdentity();

  glTranslatef(0.0,-2.0,0.0);
  glRotatef(rotation_tete,1,0,0);
  glTranslatef(0.0,2.0,0.0);

  glutSolidSphere(1.0,10.0,10.0);





  glColor3f(0.313,0.16,0.04);

  //TRONC
  glLoadIdentity();

  glTranslatef(0.0,-3.5,0.0);
  glScalef(1.0,1.0,0.2);
  glutSolidSphere(2.5,10.0,10.0);





  glColor3f(1.0,0.78,0.6);

  //BRAS DROIT
  glLoadIdentity();

  /*glTranslatef(2.5,-1.3,0.0);
  glRotatef(rc*3.5,1,0,0);
  glTranslatef(-2.5,1.3,0.0);*/

  glTranslatef(2.5,-1.3,0.0);
  glRotatef(180,1,0,0);
  glTranslatef(-2.5,1.3,0.0);

  glTranslatef(2.5,-1.3,0.0);
  glutSolidSphere(.6,10.0,10.0);  

  glTranslatef(0.4,-1.5,0.0);
  glutSolidSphere(.6,10.0,10.0);  
  
  glTranslatef(0.4,-1.5,0.0);  
  glutSolidSphere(.6,10.0,10.0);
  




  //BRAS GAUCHE
  glLoadIdentity();

  /*glTranslatef(2.5,-1.3,0.0);
  glRotatef(-rc*0.12,1,0,0);
  glTranslatef(-2.5,1.3,0.0);*/

  glRotatef(180.0,0.0,1.0,0.0);

  glTranslatef(2.5,-1.3,0.0);
  glutSolidSphere(.6,10.0,10.0);  

  glTranslatef(0.4,-1.5,0.0);
  glutSolidSphere(.6,10.0,10.0);  
  
  glTranslatef(0.4,-1.5,0.0);  
  glutSolidSphere(.6,10.0,10.0);
  



  //JAMBE DROITE
  glLoadIdentity();

  
  /*glTranslatef(1.0,-7.5,0.0);
  glRotatef(-rc*0.68,1,0,0);
  glTranslatef(-1.0,7.5,0.0);*/


  glTranslatef(1.0,-7.5,0.0);
  glutSolidSphere(0.8,10.0,10.0);

  glTranslatef(0.4,-1.9,0.0);  
  glutSolidSphere(.8,10.0,10.0);

  glTranslatef(0.4,-1.9,0.0);  
  glutSolidSphere(.8,10.0,10.0);
  


  //JAMBE GAUCHE
  glLoadIdentity();
 
  /*glTranslatef(1.0,-7.5,0.0);
  glRotatef(rc*1.15,1,0,0);
  glTranslatef(-1.0,7.5,0.0);*/
  
  glRotatef(180.0,0.0,1.0,0.0);
  
  glTranslatef(1.0,-7.5,0.0);
  glutSolidSphere(0.8,10.0,10.0);

  glTranslatef(0.4,-1.9,0.0);  
  glutSolidSphere(.8,10.0,10.0);

  glTranslatef(0.4,-1.9,0.0);  
  glutSolidSphere(.8,10.0,10.0);

  rc+=1;

  rotation_tete+=1.0*sens;
  if(rotation_tete>45.0)
    sens=-1.0f;
  if(rotation_tete<0.0)
    sens=1.0f;
  //printf("%lf\n",rotation_tete);
  
  // on échange les buffers (double buffering)
  glutSwapBuffers();
}



int main(int argc, char **argv) 
{  
  /* initialisation de glut */
  glutInit(&argc, argv);  

  /* Mode d'affichage
     RGBA color
     Double buffer      
     Alpha components supported 
     z-buffer */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* taille de la fenêtre 640 x 480 */
  glutInitWindowSize(640, 480);  

  /* la fenêtre se positionne en haut à gauche */
  glutInitWindowPosition(0, 0);  

  /* on crée la fenêtre */  
  window = glutCreateWindow("Nancy Sinatra inspired");  

  /* On 'register' la fonction de dessin */
  glutDisplayFunc(&DrawGLScene);  

  /* fullscreen */
  /* glutFullScreen(); */

  /* même sans événements, on va re dessiné la scène */
  glutIdleFunc(&DrawGLScene);
  glutMouseFunc(&mouse);
  glutMotionFunc(&mousemotion);
  glutKeyboardFunc(&clavier);
  
  /* en cas de redimensionnement */
  glutReshapeFunc(&ReSizeGLScene);
  

  /* on initialise la scène */
  InitGL(640, 480);
  
  /* On lance la boucle de la gestion d'événements */  
  glutMainLoop();  

  return 1;
}
