function affiche(data,mi,mj,theta,lambda)
  % affiche(data,mi,mj,theta,lambda)
  %
  % data : matrice image (valeurs 0 ou 1)
  % mi : ordonnee du barycentre
  % mj : abscisse du barycentre
  % theta : orientation
  % lambda : les 2 valeurs propres (vecteur)
  %
  % affiche la matrice image avec les 2 axes principaux
  % (EFFET DE BORD: modification de la matrice image)

  [li,co]=size(data);
  % place le centre de gravite (carre 3x3 de couleur gris moyen)
  data(round(mi)+0,round(mj)+0)=0.5;
  data(round(mi)+0,round(mj)-1)=0.5;
  data(round(mi)+0,round(mj)+1)=0.5;
  data(round(mi)-1,round(mj)+0)=0.5;
  data(round(mi)-1,round(mj)-1)=0.5;
  data(round(mi)-1,round(mj)+1)=0.5;
  data(round(mi)+1,round(mj)+0)=0.5;
  data(round(mi)+1,round(mj)-1)=0.5;
  data(round(mi)+1,round(mj)+1)=0.5;

  % trace l'axe principal
  m = max(lambda(1), lambda(2));
  m = sqrt(m);
  m = m*sqrt(3);  % pourquoi ?
  for k = -200:1:200,  % en trait plein
    x = round(mj+(m*k)/200*cos(theta*pi/180));
    y = round(mi-(m*k)/200*sin(theta*pi/180));
    if (0 < x) & (x < co) & (0 < y) & (y < li)
      data(y,x)=0.5;
    end
  end

  % trace l'axe secondaire
  m = min(lambda(1), lambda(2));
  m = sqrt(m);
  m = m*sqrt(3);  % pourquoi ?

  for k = -200:5:200,  % en pointillés
    x = round(mj+(m*k)/200*cos(theta*pi/180+pi/2));
    y = round(mi-(m*k)/200*sin(theta*pi/180+pi/2));
    if (0 < x) & (x < co) & (0 < y) & (y < li)
      data(y,x)=0.5;
    end
  end

  % visualise l'image
  data = 1-data;
  imshow(data);
end
