/**
Auteur : Rémi Synave
Mail : synave@labri.fr
Date : 10/10/2006
 **/

#ifndef VECTOR3D__H
#define VECTOR3D__H

#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 4*atan(1.0)
#endif


typedef struct
{
  double dx,dy,dz;
}vector3d;

/**
Initialisation d'un vector3d (dx,dy,dz)
@param v pointeur sur le vector3d
@param dx dx
@param dy dy
@param dz dz
@return aucun
 */
void
vector3d_init(vector3d *v, double dx, double dy, double dz);

/**
Affichage d'un vector3d
@param v le vector3d à afficher
@return aucun
 */
void
vector3d_display(vector3d v);

/**
Calcule la longueur d'un vector3d
@param v le vector3d à mesurer
@return taille du vector3d
 */
double
vector3d_size(vector3d v);

/**
Teste si deux vector3d sont égaux
@param v1 le premier vector3d
@param v2 le second vector3d à tester
@return 1 si les deux vector3d sont égaux, 0 sinon
 */
int
vector3d_equal(vector3d v1, vector3d v2);

/**
Normalise le vector3d : transforme le vector3d de sorte que sa longueur soit égale à 1.0
@param v poiteur sur le vector3d
@return aucun
 */
void
vector3d_normalize(vector3d *v);

/**
Produit scalaire de deux vector3d
@param v1 le premier vector3d
@param v2 le second vector3d
@return produit scalaire v1.v2
 */
double
vector3d_scalarproduct(vector3d v1, vector3d v2);

/**
Produit vectoriel de deux vector3d
@param v1 le premier vector3d
@param v2 le second vector3d
@return un vector3d résultat de v1^v2
 */
vector3d
vector3d_vectorialproduct(vector3d v1, vector3d v2);

/**
Inverse le vecteur
@param v pointeur sur le vecteur à inverser
@return aucun
 **/
void
vector3d_reverse(vector3d *v);

/**
Addition de deux vecteurs3d v1+v2
@param v1 premier vecteur
@param v2 second vecteur
@param un vector3d résultat de v1+v2
**/
vector3d
vector3d_add(vector3d v1, vector3d v2);

/**
Soustraction de deux vecteurs3d v1-v2
@param v1 premier vecteur
@param v2 second vecteur
@param un vector3d résultat de v1-v2
**/
vector3d
vector3d_sub(vector3d v1, vector3d v2);

#endif
