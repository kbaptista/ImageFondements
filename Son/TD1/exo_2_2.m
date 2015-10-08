function [tab_1, tab_2, tab_3] = exo_2_1()

freq1=356;
freq2=100;

amp = 1.0;
phi = 0.0;
Fech = 256;
N = Fech*2; % n*Fech = n secondes 

tab_1=syn_sinus(freq1, amp, phi, Fech, N);

tab_2=syn_sinus(freq2, amp, phi, Fech, N);

tab_3=tab_2+tab_1;

%fréquence d'échantillonage pas assez grande pour tab_1 (Théorème de Shanon)
%On reconstruit donc une fréquence égale à Fech - freq1

end