noise = uniform(256, 256);
figure, hist(noise, 50);
title('Histogram of uniform noise');

noise = gaussian(256, 256);
figure, hist(noise, 50);
title('Histogram of gaussian noise');

noise = logn(256, 256);
figure, hist(noise, 50);
title('Histogram of normal log noise');

noise = relay(256, 256);
figure, hist(noise, 50);
title('Histogram of Relay noise');

noise = exponential(256, 256);
figure, hist(noise, 50);
title('Histogram of exponential noise');

noise = erlang(256, 256);
figure, hist(noise, 50);
title('Histogram of Erlang noise');

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