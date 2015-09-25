/**
Auteur : Rémi synave
Mail : synave@labri.fr
Date : 18/09/2008
 **/

#ifndef QUATERNION__H
#define QUATERNION__H

#include <stdio.h>
#include <stdlib.h>
#include "vector3d.h"
#include "point.h"

typedef struct
{
  double w;
  vector3d V;
}quaternion;


void
quaternion_display(quaternion q);

void
quaternion_init(quaternion *q, double mw, double mx, double my, double mz);

quaternion
quaternion_add(quaternion q1, quaternion q2);

quaternion
quaternion_mul(quaternion q1, quaternion q2);

quaternion
quaternion_conjugate(quaternion q);

double
quaternion_module(quaternion q);

quaternion
quaternion_inverse(quaternion q);

quaternion
quaternion_normalize(quaternion q);

#endif
