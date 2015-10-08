function exo_3(file)

Fech = 44100;

s=wavread(file);
y=s(1:2:length(s));
wavwrite(y, Fech/2, 'test.wav');

y=s(1:4:length(s));
wavwrite(y, Fech/4, 'test2.wav');

y=s(1:8:length(s));
wavwrite(y, Fech/8, 'test3.wav');

end