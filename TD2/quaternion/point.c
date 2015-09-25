/**
Auteur : Rémi Synave
Mail : synave@labri.fr
Date : 10/10/2006
 **/
 
#include "point.h"

/**
Initialisation d'un point3d (x,y,z)
@param p pointeur sur un point3d
@param x
@param y
@param z
@return aucun
 */
void 
point3d_init(point3d *p, double x, double y, double z)
{
  p->x=x;
  p->y=y;
  p->z=z;
}

/**
Affichage d'un point3d
@param p le point
@return aucun
**/
void
point3d_display(point3d p)
{
  printf("POINT --> (%lf , %lf , %lf)\n",p.x,p.y,p.z);
}

/**
Teste l'égalité de 2 points
@param p1 premier point
@param p2 second point
@return 1 si p1==p2, 0 sinon
 */
int
point3d_equal(point3d p1, point3d p2)
{
  return(p1.x==p2.x && p1.y==p2.y && p1.z==p2.z);
}
