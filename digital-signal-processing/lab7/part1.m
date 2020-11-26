I = imread('resources/gray.bmp');
%I = imresize(I, 15);                   % to encrease the number of black/white pixels
W = imread('resources/watermark.bmp'); % watermark

[C, capacity] = getContainer(I);
fprintf("Container capacity: %0.1f bytes\n", capacity);
IW = C;                                % image with watermark

for i = 1:size(W, 1)
   for j = 1:size(W, 2)
       for k = 1:size(IW, 3)
           if (W(i, j) > 0)
               IW(i,j,k) = IW(i,j,k) + 1;
           end
       end
   end
end

figure, imhist(I)
title('Input image histogram')
figure, imhist(C)
title('Container histogram')
figure, imhist(IW)
title('Image with watermark histogram')

fprintf("Correlation between input img and container: %0.4f\n", corr2(I(:,:,1), C(:,:,1)));
fprintf("Correlation between input img and output img: %0.4f\n", corr2(I(:,:,1), IW(:,:,1)));

W = IW;
for i = 1:size(IW, 1)
   for j = 1:size(IW, 2)
       for k = 1:size(IW, 3)
           IW(i,j,k) = bitand(IW(i,j,k), uint8(254));
           W(i,j,k) = (W(i,j,k) - IW(i,j,k)) * 256;
       end
   end
end

figure, imshow(W);
title('Result watermark')

function [IW, capacity] = getContainer(I)
    capacity = 0;
    IW = I;
    for i = 1:size(IW, 1)
       for j = 1:size(IW, 2)
           for k = 1:size(IW, 3)
               IW(i,j,k) = bitand(IW(i,j,k), uint8(254));
               capacity = capacity + 1;
           end
       end
    end
    capacity = capacity / 8;
end