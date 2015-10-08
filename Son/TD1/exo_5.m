function []=exo_5()

	freq=440;
	amp = 1.0;
	phi = 0.0;
	Fech = 44100;
	N = Fech*2;
	nbits = 8;
	mu=255; %coefficient pour la quantification non linéaire
	n_valeurs=2^(nbits-1);

	s=wavread('Toms_diner.wav');

	% fonction de compression
	s_comp=sign(s).*(log(1+abs(s).*mu)/log(1+mu));

	% quantification linéaire
	s_quant=round(s_comp.*n_valeurs)./n_valeurs;

	%fonction expansion / inverse de la compression
	s_expans=(sign(s_quant).*(1/mu)).*(exp(abs(s_quant).*(log(1+mu)))-1);

	auwrite(s_expans, 44100, 8, 'mu', 'tomsmu.au');
	s8=wavread('Toms_diner8bits.wav');
	auwrite(s_expans, 44100, 8, 'linear', 'tomslin.au');

end