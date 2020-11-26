f = imread('foto.jpg');
f = f(:,:,2);
Mask = zeros(size(f));
Mask(24, 69) = 1;
Mask(97, 87) = 1;
Mask(40, 60) = 1;
Mask(80, 50) = 1;
[g, NR, SI]= regiongrow(f, Mask, 30);
figure, imshow(f)
figure, imshow(g)
figure, imshow(SI)

f(~g) = 0;
figure, imshow(f)