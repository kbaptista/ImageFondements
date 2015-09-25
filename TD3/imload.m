function [data, ngmax]=imload(name)
  % data=imload(name)
  %
  % name : PGM-raw file (containing black-and-white pixels)
  % data : image matrix
  %
  % load an image from a PGM-raw file of the given name
  % and return its pixel map in the data matrix
  % [similar to MatLab: data=imread(name)]
  file=fopen(name,'r');
  if file == -1
    printf('%s: cannot open file\n',name);
    data=[];
  else
    [string,length]=fgets(file);  % skip P5 header
    if (string(1) != 'P') | (string(2) != '5')
      printf('%s: not a PGM-raw file\n',name);
      data=[];
    else
      string='#';
      while string(1) == '#'
	[string,length]=fgets(file);  % skip comments
      end
      % parse width and height
      [s,count]=sscanf(string,'%d %d');
      co=s(1);
      li=s(2);
      % parse depth
      [string,length]=fgets(file);
      ngmax=sscanf(string,'%d');
      [data,count]=fread(file,[co li],'uchar');
      data=data';
      fclose(file);
    end
  end
end
