function [s] = syn_sinus(freq, amp, phi, Fech, N)

n=1:N;
s=amp*sin(2*pi*freq*n/Fech+phi);

end