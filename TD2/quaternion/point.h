/**
Auteur : Rémi Synave
Mail : synave@labri.fr
Date : 10/10/2006
 **/
 
#ifndef POINT__H
#define POINT__H

#include <stdio.h>

/**
Structure point3d
 */
typedef struct
{
  double x,y,z;
}point3d;

/**
Initialisation d'un point3d (x,y,z)
@param p pointeur sur un point3d
@param x
@param y
@param z
@return aucun
 */
void 
point3d_init(point3d *p, double x, double y, double z);

/**
Affichage d'un point3d
@param p le point
@return aucun
**/
void
point3d_display(point3d p);

/**
Teste l'égalité de 2 points
@param p1 premier point
@param p2 second point
@return 1 si p1==p2, 0 sinon
 */
int
point3d_equal(point3d p1, point3d p2);

#endif
