f = imread('foto.jpg');
f = f(:,:,2);
q = splitmerge(f, 2, 10, 15, 255);

figure, imshow(f)
figure, imshow(q)