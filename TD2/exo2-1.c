#include <GL/glut.h>    // GLUT Library 
#include <GL/gl.h>	// OpenGL32 Library
#include <GL/glu.h>	// GLu32 Library2

int window; 

GLubyte indices[] = {0,1,2,3,
		     1,5,6,2,
		     5,4,7,6,
		     0,3,7,4,
		     2,6,7,3,
		     1,0,4,5};

GLdouble vertices[] = {-1,-1,-1,
		       1,-1,-1,
		       1,1,-1,
		       -1,1,-1,
		       -1,-1,1,
		       1,-1,1,
		       1,1,1,
		       -1,1,1};  

// color array
GLfloat colors[] = {1,1,1,
		    1,1,0,
		    1,0,0,
		    1,0,1,    
		    0,0,1,
		    0,1,1,        
		    0,1,0,            
		    0,0,0};

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
   
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);  
  glColorPointer(3, GL_FLOAT, 0, colors);
  glVertexPointer(3, GL_DOUBLE, 0, vertices);

  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glLoadIdentity();				// on ré initialise le point de vue de la scène

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
     claviers spéciaux (F1;F2,...) => glutSpecialFunc(void (*func) (int key, int x, int y));
     souris => MouseFunc(void (*func)(int button, int state, int x, int y));
     en fonction du temps => glutTimerFunc(unsigned int msecs, void (*func)(int value), value);
  */
  /* en cas de redimensionnement */
  glutReshapeFunc(&ReSizeGLScene);
  

  /* on initialise la scène */
  InitGL(640, 480);
  
  /* On lance la boucle de la gestion d'événements */  
  glutMainLoop();  

  return 1;
}
