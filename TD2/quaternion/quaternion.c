/**
Auteur : Rémi Synave
Mail : synave@labri.fr
Date : 10/10/2006
 **/
 
#include "quaternion.h"

void
quaternion_display(quaternion q)
{
  printf("Quaternion : (%lf , %lf , %lf , %lf)\n",q.w,q.V.dx,q.V.dy,q.V.dz);
}

void
quaternion_init(quaternion *q,double mw, double mx, double my, double mz)
{
  q->w=mw;
  vector3d_init(&(q->V),mx,my,mz);
}

quaternion
quaternion_add(quaternion q1, quaternion q2)
{
  quaternion res;
  vector3d vec_add=vector3d_add(q1.V,q2.V);
  quaternion_init(&res,q1.w+q2.w,vec_add.dx,vec_add.dy,vec_add.dz);
  
  return res;
}

quaternion
quaternion_mul(quaternion q1, quaternion q2)
{
  quaternion res;
  double prodscal=vector3d_scalarproduct(q1.V,q2.V);
  vector3d prodvec=vector3d_vectorialproduct(q1.V,q2.V);
  vector3d wVp,wpV,vec_add;
  
  vector3d_init(&wVp,q1.w*q2.V.dx,q1.w*q2.V.dy,q1.w*q2.V.dz);
  vector3d_init(&wpV,q2.w*q1.V.dx,q2.w*q1.V.dy,q2.w*q1.V.dz);
  
  vec_add=vector3d_add(wVp,vector3d_add(wpV,prodvec));
  
  quaternion_init(&res,q1.w*q2.w-prodscal,vec_add.dx,vec_add.dy,vec_add.dz);
  
  return res;
}

quaternion
quaternion_conjugate(quaternion q)
{
  quaternion res;
  
  quaternion_init(&res,q.w,-q.V.dx,-q.V.dy,-q.V.dz);
  
  return res;
}

double
quaternion_module(quaternion q)
{
  return(sqrt(q.w*q.w+q.V.dx*q.V.dx+q.V.dy*q.V.dy+q.V.dz*q.V.dz));
}

quaternion
quaternion_inverse(quaternion q)
{
  quaternion res;
  quaternion conj=quaternion_conjugate(q);
  double modulecarre=quaternion_module(q)*quaternion_module(q);
  
  quaternion_init(&res,conj.w/modulecarre,conj.V.dx/modulecarre,conj.V.dy/modulecarre,conj.V.dz/modulecarre);
  
  return res;
}

quaternion
quaternion_normalize(quaternion q)
{
  quaternion res;
  double module=quaternion_module(q);  
  
  quaternion_display(res);
  printf("\n");
  quaternion_init(&res,q.w/module,q.V.dx/module,q.V.dy/module,q.V.dz/module);
  quaternion_display(res);
  return res;
  
}

void
quaternion_to_matrix(quaternion q, double * res)
{
  double w = q.w;
  double x = q.V.dx;
  double y = q.V.dy;
  double z = q.V.dz;
  double this [16] = {
    1.0-2*(y*y + z*z), 2 *(x*y - w*z), 2*(x*z + w*y), 0.0,
    2*(x*y + w*z), 1.0-2*(x*x + z*z),  2*(y*z - w*x), 0.0,
    2*(x*z - w*y), 2 *(x*y + w*z), 1.0-2*(y*y + x*x), 0.0,
        0.0,              0.0,            0.0,        1.0,
  };

  res = this ;
}