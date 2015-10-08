function [s] = syn_creneaux(freq, amp, phi, Fech, N)

n=1:N;
s=amp*sin(2*pi*freq*n/Fech+phi);
/* pour chaque valeur se s, si s<0, alors s =-1, si s>0 s=1*/
end