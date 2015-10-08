function [tab_1, tab_2, tab_3] = exo_2_1()

tab_1=syn_sinus(100, 1.0, 0, 256, 256*5);

tab_2=syn_sinus(156, 1.0, 0, 256, 256*5);

tab_3=tab_2+tab_1;

%fréquence d'échantillonage pas assez grande pour tab_2 (Théorème de Shanon)
%On reconstruit donc une fréquence égale à freq de tab_2 + Fech

end