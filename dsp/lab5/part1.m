f = imread('resources/gray.jpg');      
figure, imshow(f)
g = im2jpeg(f);

f = jpeg2im(g);
figure, imshow(f)