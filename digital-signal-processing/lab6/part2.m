size = 256;

i = imread('resources/gray.jpg');
i = imresize(i, 0.5);               % 512x512 to 256x256
i = im2double(i);

n = i + uniform(size, size);
imwrite(n, 'resources/uniform/img_uniform_noise.png');

n = i + gaussian(size, size);
imwrite(n, 'resources/gaussian/img_gaussian_noise.png');

n = i + logn(size, size);
imwrite(n, 'resources/log/img_log_noise.png');

n = i + relay(size, size);
imwrite(n, 'resources/relay/img_relay_noise.png');

n = i + exponential(size, size);
imwrite(n, 'resources/exp/img_exp_noise.png');

n = i + erlang(size, size);
imwrite(n, 'resources/erlang/img_erlang_noise.png');

function x = uniform(n, m)
    x = rand(n, m);
end

function x = gaussian(n, m)
    x = 0.15 * randn(n, m);
end

function x = logn(n, m)
    x = exp(0.25 * randn(n, m));
end

function x = relay(n, m)
    x = sqrt(-log(1 - rand(n, m)));
end

function x = exponential(n, m)
    x =  -log(1 - rand(n, m));
end

function x = erlang(n, m)
    x = -0.5 * 5 * log(1 - rand(n, m));
end