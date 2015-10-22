function analyse(nom_fichier)
  % nom_fichier : nom du fichier image au format pgm (en noir et blanc)

  %Partie 2
  
  [I, ngmax] = imload(nom_fichier);
  ngmax
  I = I /ngmax;
 
  if mean(mean(I)) >= 0.5
    I = 1-I;
  end
  
  %Partie 3
  
  
  li = rows(I)
  co = columns(I)
  
  s = 0;
  for i = 1:li
    for j= 1: co
      s = s + I(i,j);
      endfor
  endfor
  s
  
  mi=0;
  for i = 1:li
    for j= 1: co
      mi = mi + I(i,j)*i;
      endfor
  endfor
  mi  = mi/s
  
  mj=0;
  for i= 1:li
    for j =1: co
      mj = mj + I(i,j)*j;
      endfor
  endfor
  mj  = mj/s
  
  sii=0;
  for i =1:li
    for j =1: co
      sii = sii + I(i,j)*(i-mi)*(i-mi);
      endfor
  endfor
  sii = sii/s    
  
  
  sij=0;
  for i= 1:li
    for j= 1: co
      sij = sij+I(i,j)*(i-mi)*(j-mj);
      endfor
  endfor
  sij = sij/s
  
  sji = sij
  
  sjj=0;
  for i =1:li
    for j= 1: co
      sjj = sjj + I(i,j)*(co-mj)*(co-mj);
      endfor
  endfor
  sjj=sjj/s
  
  %Partie 4
  
  printf("\nMatrice de Covariance\n")
  C = [sii sij ; sji sjj]
  
  printf("\nMatrice de Covariance diagonalisée\n")
  D = eig(C)
  
  
  
  
endfunction
