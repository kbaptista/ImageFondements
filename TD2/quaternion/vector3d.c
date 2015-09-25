/**
Auteur : Rémi Synave
Mail : synave@labri.fr
Date : 10/10/2006
 **/
 
#include "vector3d.h"

/**
Initialisation d'un vector3d (dx,dy,dz)
@param v pointeur sur le vector3d
@param dx dx
@param dy dy
@param dz dz
@return aucun
 */
void
vector3d_init(vector3d *v, double dx, double dy, double dz)
{
  v->dx=dx;
  v->dy=dy;
  v->dz=dz;
}

/**
Affichage d'un vector3d
@param v le vector3d à afficher
@return aucun
 */
void
vector3d_display(vector3d v)
{
  printf("VECTOR --> (%lf , %lf , %lf)\n",v.dx,v.dy,v.dz);
}

/**
Calcule la longueur d'un vector3d
@param v le vector3d à mesurer
@return taille du vector3d
 */
double
vector3d_size(vector3d v)
{
  return sqrt(v.dx*v.dx+v.dy*v.dy+v.dz*v.dz);
}

/**
Teste si deux vector3d sont égaux
@param v1 le premier vector3d
@param v2 le second vector3d à tester
@return 1 si les deux vector3d sont égaux, 0 sinon
 */
int
vector3d_equal(vector3d v1, vector3d v2)
{
  return (v1.dx==v2.dx && v1.dy==v2.dy && v1.dz==v2.dz);
}

/**
Normalise le vector3d : transforme le vector3d de sorte que sa longueur soit égale à 1.0
@param v poiteur sur le vector3d
@return aucun
 */
void
vector3d_normalize(vector3d *v)
{
  if(v->dx==0 && v->dy==0 && v->dz==0)
    return;

  double size=vector3d_size(*v);
  v->dx/=size;
  v->dy/=size;
  v->dz/=size;
}

/**
Produit scalaire de deux vector3d
@param v1 le premier vector3d
@param v2 le second vector3d
@return produit scalaire v1.v2
 */
double
vector3d_scalarproduct(vector3d v1, vector3d v2)
{
  return v1.dx*v2.dx+v1.dy*v2.dy+v1.dz*v2.dz;
}

/**
Produit vectoriel de deux vector3d
@param v1 le premier vector3d
@param v2 le second vector3d
@return un vector3d résultat de v1^v2
 */
vector3d
vector3d_vectorialproduct(vector3d v1, vector3d v2)
{
  vector3d W;

  W.dx=v1.dy*v2.dz-v1.dz*v2.dy;
  W.dy=-(v1.dx*v2.dz-v1.dz*v2.dx);
  W.dz=v1.dx*v2.dy-v1.dy*v2.dx;

  return W;
}

/**
Inverse le vecteur
@param v pointeur sur le vecteur à inverser
@return aucun
 **/
void
vector3d_reverse(vector3d *v)
{
  v->dx*=-1;
  v->dy*=-1;
  v->dz*=-1;
}

/**
Addition de deux vecteurs3d v1+v2
@param v1 premier vecteur
@param v2 second vecteur
@param un vector3d résultat de v1+v2
**/
vector3d
vector3d_add(vector3d v1, vector3d v2)
{
  vector3d v;
  v.dx=v1.dx+v2.dx;
  v.dy=v1.dy+v2.dy;
  v.dz=v1.dz+v2.dz;
  return v;
}

/**
Soustraction de deux vecteurs3d v1-v2
@param v1 premier vecteur
@param v2 second vecteur
@param un vector3d résultat de v1-v2
**/
vector3d
vector3d_sub(vector3d v1, vector3d v2)
{
  vector3d v;
  v.dx=v1.dx-v2.dx;
  v.dy=v1.dy-v2.dy;
  v.dz=v1.dz-v2.dz;
  return v;
}
