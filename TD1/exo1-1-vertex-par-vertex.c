#include <GL/glut.h>    // GLUT Library 
#include <GL/gl.h>	// OpenGL32 Library
#include <GL/glu.h>	// GLu32 Library

int window; 

/* angle de rotation pour notre carre */
float rcx = 0.0f;
float rcy = 0.0f;




void mouse(int button,int state,int x,int y) ; //détecte qu'un bouton est appuyé

void mousemotion(int x,int y) ; //calcul et applique le déplacement (x et y sont les positions de la souris dans la fenêtre au moment de l'appel de la fonction.)
void keyboard(unsigned char touche,int x,int y) ;

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

  glTranslatef(0.0f,0.0f,-10.0f);		// on translate la scène vers le fond
	
  glRotatef(rcy,0.0f,1.0f,0.0f);		// on fait tourner la scène sur l'axe des Y
  glRotatef(rcx,1.0f,0.0f,0.0f);		// on fait tourner la scène sur l'axe des X

  // on dessine le carré #1 
  glBegin(GL_QUADS);		// début du dessin
  glColor3f ( 1.0f, 0.0f, 0.0f);	// couleur Rouge
  glVertex3f(-1.0f, 1.0f, 1.0f);  // coordonnées du 1e vertex
  glColor3f ( 0.0f, 1.0f, 0.0f);  // couleur Vert
  glVertex3f( 1.0f, 1.0f, 1.0f);  // coordonnées du 2eme vertex 
  glColor3f ( 0.0f, 0.0f, 1.0f);  // couleur Bleu
  glVertex3f( 1.0f,-1.0f, 1.0f);  //3
  glColor3f ( 1.0f, 1.0f, 0.0f);  // couleur Jaune  
  glVertex3f(-1.0f,-1.0f, 1.0f);  //4

  // on dessine le carré #2
  glBegin(GL_QUADS);    // début du dessin

  glColor3f ( 1.0f, 0.0f, 0.0f);  // couleur Rouge
  glVertex3f(-1.0f, 1.0f, 1.0f);// coordonnées du 1e vertex
  glColor3f ( 1.0f, 1.0f, 0.0f);  // couleur Jaune  
  glVertex3f(-1.0f,-1.0f, 1.0f);
  glColor3f ( 1.0f, 1.0f, 1.0f); // blanc
  glVertex3f(-1.0f,-1.0f,-1.0f);
  glColor3f ( 1.0f, 0.0f, 1.0f); // Rose
  glVertex3f(-1.0f, 1.0f,-1.0f);

  // on dessine le carré #3
  glBegin(GL_QUADS);    // début du dessin
  glColor3f ( 1.0f, 0.0f, 1.0f); // Rose
  glVertex3f(-1.0f, 1.0f,-1.0f);// coordonnées du 1e vertex
  glColor3f ( 1.0f, 0.5f, 0.0f); // orange
  glVertex3f( 1.0f, 1.0f,-1.0f);// coordonnées du 2eme vertex 
  glColor3f ( 0.5f, 0.0f, 1.0f); // Violet
  glVertex3f( 1.0f,-1.0f,-1.0f);
  glColor3f ( 1.0f, 1.0f, 1.0f); // blanc
  glVertex3f(-1.0f,-1.0f,-1.0f);

  // on dessine le carré #4
  glBegin(GL_QUADS);    // début du dessin
  glColor3f ( 0.0f, 1.0f, 0.0f);  // couleur Vert
  glVertex3f( 1.0f, 1.0f, 1.0f);  // coordonnées du 2eme vertex 
  glColor3f ( 1.0f, 0.5f, 0.0f); // orange
  glVertex3f( 1.0f, 1.0f,-1.0f);// coordonnées du 2eme vertex 
  glColor3f ( 0.5f, 0.0f, 1.0f); // Violet
  glVertex3f( 1.0f,-1.0f,-1.0f);
  glColor3f ( 0.0f, 0.0f, 1.0f);  // couleur Bleu
  glVertex3f( 1.0f,-1.0f, 1.0f);  //3

  // on dessine le carré #5
  glBegin(GL_QUADS);    // début du dessin
  glColor3f ( 1.0f, 0.0f, 0.0f);  // couleur Rouge
  glVertex3f(-1.0f, 1.0f, 1.0f);  // coordonnées du 1e vertex
  glColor3f ( 0.0f, 1.0f, 0.0f);  // couleur Vert
  glVertex3f( 1.0f, 1.0f, 1.0f);  // coordonnées du 2eme vertex 
  glColor3f ( 1.0f, 0.5f, 0.0f); // orange
  glVertex3f( 1.0f, 1.0f,-1.0f);// coordonnées du 2eme vertex 
  glColor3f ( 1.0f, 0.0f, 1.0f); // Rose
  glVertex3f(-1.0f, 1.0f,-1.0f);// coordonnées du 1e vertex

  // on dessine le carré #6
  glBegin(GL_QUADS);    // début du dessin
  glColor3f ( 0.0f, 0.0f, 1.0f);  // couleur Bleu
  glVertex3f( 1.0f,-1.0f, 1.0f);  //3
  glColor3f ( 1.0f, 1.0f, 0.0f);  // couleur Jaune  
  glVertex3f(-1.0f,-1.0f, 1.0f);  //4
  glColor3f ( 1.0f, 1.0f, 1.0f); // blanc
  glVertex3f(-1.0f,-1.0f,-1.0f);
  glColor3f ( 0.5f, 0.0f, 1.0f); // Violet
  glVertex3f( 1.0f,-1.0f,-1.0f);


/*
  glColor3f ( 1.0f, 1.0f, 1.0f);
*/
  glEnd();
 
  glLoadIdentity();				// on ré initialise le point de vue de la scène
	
  rcx += 0.5f;					// Augmente la variable pour la rotation du carre sur l'axe des x
  rcy += 0.25f;					// Augmente la variable pour la rotation du carre sur l'axe des y

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

  /* en cas de redimensionnement */
  glutReshapeFunc(&ReSizeGLScene);
  

  /* on initialise la scène */
  InitGL(640, 480);
  
  /* On lance la boucle de la gestion d'événements */  
  glutMainLoop();  

  return 1;
}
