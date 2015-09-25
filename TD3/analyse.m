function analyse(nom_fichier)
  % nom_fichier : nom du fichier image au format pgm (en noir et blanc)

  %Partie 2
  
  [I, ngmax] = imload(nom_fichier);
  
  I = I /256;
 
  if mean(mean(I)) >= 0.5
    I = 1-I;
  end
  
  %Partie 3
  
  li = rows(I)
  co = columns(I)
  
  s   = sum(sum(I))
  
  mi  = (sum(sum(I))*li)
  mj  = (sum(sum(I))*co)
  
  
  sii = (sum(sum(I))*(li-mi)*(li-mi))
  sij = (sum(sum(I))*(li-mi)*(co-mj))
  sji = sij
  sjj = (sum(sum(I))*(co-mj)*(co-mj))
  
  %Partie 4
  
  printf("\nMatrice de Covariance\n")
  C = [sii sij ; sji sjj]
  
  printf("\nMatrice de Covariance diagonalisée\n")
  D = eig(C)
  
  
  
  
endfunction
