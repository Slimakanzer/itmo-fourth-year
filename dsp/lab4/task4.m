f = imread('foto.jpg');
f = f(:,:,2);

r = roberts(f, 0.1);
s = sobel(f, 0.51);
p = previtt(f, 0.3);

figure, imshow(f)
figure, imshow(r)
figure, imshow(s)
figure, imshow(p)

function g = roberts(f, T)
x_mask = [
        0 0 0
        0 -1 0
        0 0 1
        ];
y_mask = [
        0 0 0
        0 0 -1
        0 1 0
        ];
g = imgradient(f, T, x_mask, y_mask);
end

function g = sobel(f, T)
x_mask = [
        -1 -2 -1
        0 0 0
        1 2 1
        ];
y_mask = [
        -1 0 1
        -2 0 2
        -1 0 1
        ];
g = imgradient(f, T, x_mask, y_mask);
end

function g = previtt(f, T)
x_mask = [
        -1 -1 -1
        0 0 0
        1 1 1
        ];
y_mask = [
        -1 0 1
        -1 0 1
        -1 0 1
        ];
g = imgradient(f, T, x_mask, y_mask);
end