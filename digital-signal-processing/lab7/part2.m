image = imread('resources/gray.bmp');
watermark = imread('resources/watermark.bmp');
image = imresize(image, 15);    % to encrease the number of black/white pixels

figure, imshow(watermark)
title('Input watermark')

[container, capacity] = getContainer(image);
fprintf("Container capacity: %0.1f bytes\n", capacity);
assert(capacity >= numel(size(watermark)), "Not enough black/white pixels");

imageWithWatermark = setWatermark(container, watermark);
watermark = getWatermark(imageWithWatermark, size(watermark));

figure, imshow(watermark)
title('Result watermark')

figure, imhist(image)
title('Input image histogram')
figure, imhist(container)
title('Container histogram')
figure, imhist(imageWithWatermark)
title('Image with watermark histogram')

fprintf("Correlation between input img and container: %0.4f\n", corr2(image(:,:,1), container(:,:,1)));
fprintf("Correlation between input img and output img: %0.4f\n", corr2(image(:,:,1), imageWithWatermark(:,:,1)));

function [IW, capacity] = getContainer(I)
    capacity = 0;
    IW = I;
    for i = 1:size(IW, 1)
       for j = 1:size(IW, 2)
           for k = 1:size(IW, 3)
               byte = IW(i,j,k);
               if (byte < uint8(16) || byte > uint8(239))
                   capacity = capacity + 1;
                   IW(i,j,k) = bitand(byte, 240);
               end
           end
       end
    end
    capacity = capacity / 2; % only 4 bits are stored in black/white pixel
end

function IW = setWatermark(I, W)
    n = 1; 
    m = 1;
    is_upper = 0;
    IW = I;
    for i = 1:size(IW, 1)
       for j = 1:size(IW, 2)
           for k = 1:size(IW, 3)
               if (n == size(W, 1) && m == size(W, 2))
                   return;
               end

               byte = IW(i,j,k);
               if (byte == 0 || byte == 240)
                   
                wbyte = uint8(W(n,m));
                if (mod(is_upper, 2) ==0)
                    wbyte = bitand(wbyte, 15);  % lower 4 bits
                    is_upper = 1;
                else
                    wbyte = bitand(wbyte, 240);
                    wbyte = wbyte / 16;
                    is_upper = 0;

                    m = m + 1;
                    if (m == size(W, 2) + 1)
                        n = n + 1;
                        m = 1;
                    end
                end

                IW(i,j,k) = byte + wbyte;
               end
           end
       end
    end
    
    assert(n == size(W, 1) && m == size(W, 2), "Not enough dark and light pixels");
end

function W = getWatermark(IW, sizeW)
    n = 1; 
    m = 1;
    is_upper = 0;
    W = zeros(sizeW);
    for i = 1:size(IW, 1)
       for j = 1:size(IW, 2)
           for k = 1:size(IW, 3)
               if (n == size(W, 1) && m == size(W, 2))
                   return;
               end

               byte = IW(i,j,k);
               if (byte < uint8(16) || byte > uint8(239))
                if (mod(is_upper, 2) ==0)
                   byte = byte * 16;
                   byte = byte / 16;
                   W(n,m) = byte;
                   is_upper = 1;
                else
                   byte = byte / 16;
                   byte = byte * 16;
                   W(n,m) = W(n,m) + byte;
                   is_upper = 0;

                   m = m + 1;
                   if (m == size(W, 2) + 1)
                      n = n + 1;
                      m = 1;
                   end
                end
               end
           end
       end
    end
end