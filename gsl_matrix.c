#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_matrix.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 4*atan(1.0)
#endif
      
int main (void)
{
  int i, j; 
  srand(time(NULL));
       
  gsl_matrix * mm = gsl_matrix_alloc (4, 4); // création d'un matrice 4X4
  for (i=0;i<4;i++)
    for (j=0;j<4;j++)
      gsl_matrix_set(mm,i,j,rand());       // rempli aléatoirement
       
       
  gsl_matrix * m = gsl_matrix_alloc (4, 4); // une autre matrice 4x4
       
  /* gsl_matrix_set (m, 0,0 , 1.0f); // qui sera une matrice identité */
  /* gsl_matrix_set (m, 0,1 , (float)cos(90 * M_PI/180)); */
  /* gsl_matrix_set (m, 0,2 , 0.0f); */
  /* gsl_matrix_set (m, 0,3 , 0.0f); */
  /* gsl_matrix_set (m, 1,0 , 0.0f); */
  /* gsl_matrix_set (m, 1,1 , 1.0f); */
  /* gsl_matrix_set (m, 1,2 , 0.0f); */
  /* gsl_matrix_set (m, 1,3 , 0.0f); */
  /* gsl_matrix_set (m, 2,0 , 0.0f); */
  /* gsl_matrix_set (m, 2,1 , 0.0f); */
  /* gsl_matrix_set (m, 2,2 , 1.0f); */
  /* gsl_matrix_set (m, 2,3 , 0.0f); */
  /* gsl_matrix_set (m, 3,0 , 0.0f); */
  /* gsl_matrix_set (m, 3,1 , 0.0f); */
  /* gsl_matrix_set (m, 3,2 , 0.0f); */
  /* gsl_matrix_set (m, 3,3 , 1.0f); */

  gsl_matrix_set (m, 0,0 , 1.0f);// qui sera une matrice identité
  gsl_matrix_set (m, 0,1 , 0.0f);
  gsl_matrix_set (m, 0,2 , 0.0f);
  gsl_matrix_set (m, 0,3 , 0.0f);
  gsl_matrix_set (m, 1,0 , 0.0f);
  gsl_matrix_set (m, 1,1 , 1.0f);
  gsl_matrix_set (m, 1,2 , 0.0f);
  gsl_matrix_set (m, 1,3 , 0.0f);
  gsl_matrix_set (m, 2,0 , 0.0f);
  gsl_matrix_set (m, 2,1 , 0.0f);
  gsl_matrix_set (m, 2,2 , 1.0f);
  gsl_matrix_set (m, 2,3 , 0.0f);
  gsl_matrix_set (m, 3,0 , 0.0f);
  gsl_matrix_set (m, 3,1 , 0.0f);
  gsl_matrix_set (m, 3,2 , 0.0f);
  gsl_matrix_set (m, 3,3 , 1.0f);
       
  for (i = 0; i < 4; i++)  
    for (j = 0; j < 4; j++)
      printf ("mm(%d,%d) = %f\n", i, j, 
	      gsl_matrix_get (mm, i, j));  // on regarde le contenu 
     
  gsl_matrix_mul_elements(m,mm);   // multiplication élément par élément identité*matrice quelconque

  for (i = 0; i < 4; i++)  
    for (j = 0; j < 4; j++)
      printf ("m(%d,%d) = %f\n", i, j, 
	      gsl_matrix_get (mm, i, j));

  gsl_matrix_free (m);
  gsl_matrix_free (mm);
  return 0;
}
