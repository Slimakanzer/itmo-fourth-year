size = 256;
sources = ["uniform", "gaussian", "log", "relay", "exp", "erlang"];

is = imread('resources/gray.jpg');
is = imresize(i, 0.5);               % 512x512 to 256x256
is = im2double(i);

for i = 1:length(sources)
    name = sources(i);
    dir = sprintf('resources/%s', name);
    str = sprintf('%s/img_%s_noise.png', dir, name);
    i = imread(str);
    i = im2double(i);

    ir = mean_filter(i);
    str = sprintf('%s/img_mean_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise mean filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = geometric_mean_filter(i);
    str = sprintf('%s/img_geometric_mean_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise geometric mean filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = harmonic_mean_filter(i);
    str = sprintf('%s/img_harmonic_mean_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise harmonic mean filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = contrharmonic_mean_filter(i, 2);
    str = sprintf('%s/img_contrharmonic_mean_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise contrharmonic mean filter with Q=2 Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = median_filter(i);
    str = sprintf('%s/img_median_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise median filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = max_filter(i);
    str = sprintf('%s/img_max_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise max filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = min_filter(i);
    str = sprintf('%s/img_min_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise min filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = avg_filter(i);
    str = sprintf('%s/img_avg_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise avg filter Pirson correlation: %.4f\n', name, corr2(is, ir));
    
    ir = alpha_truncated_filter(i, 4);
    str = sprintf('%s/img_alpha_truncated_filter.png', dir);
    imwrite(ir, str);
    fprintf('%s noise alpha truncated filter with d=4 Pirson correlation: %.4f\n', name, corr2(is, ir));
end

function g = imfilter3x3(f, func)
    f = im2double(f);
    g = zeros(size(f));
    for i = 2:1:size(f,1)-1
        for j = 2:1:size(f,2)-1
            mask = f(i-1:i+1,j-1:j+1);
            g(i,j) = func(mask);
        end
    end
end

function g = mean_filter(f)
    func = @(x) sum(sum(x)) / 9;
    g = imfilter3x3(f, func);
end

function g = geometric_mean_filter(f)
    func = @(x) sum(prod(x(:))) ^ (1 / 9);
    g = imfilter3x3(f, func);
end

function g = harmonic_mean_filter(f)
    func = @(x) 9 / sum(sum(ones(3, 3) ./ x));
    g = imfilter3x3(f, func);
end

function g = contrharmonic_mean_filter(f, q)
    func = @(x) sum(sum(x.^(q+1))) / sum(sum(x.^q));
    g = imfilter3x3(f, func);
end

function g = median_filter(f)
    func = @(x) median(x(:));
    g = imfilter3x3(f, func);
end

function g = max_filter(f)
    func = @(x) max(x(:));
    g = imfilter3x3(f, func);
end

function g = min_filter(f)
    func = @(x) min(x(:));
    g = imfilter3x3(f, func);
end

function g = avg_filter(f)
    func = @(x) (max(x(:)) + min(x(:))) / 2;
    g = imfilter3x3(f, func);
end

function g = alpha_truncated_filter(f, d)
    f = im2double(f);
    g = zeros(size(f));
    for i = 2:1:size(f,1)-1
        for j = 2:1:size(f,2)-1
            mask = f(i-1:i+1,j-1:j+1);
            x = sort(mask(:));
            x = x(1+d/2:end);
            x = x(1:end - d/2);
            
            g(i,j) = sum(x) / (9 - d);
        end
    end
end
