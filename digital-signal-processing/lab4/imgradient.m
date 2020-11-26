function g = imgradient(f, T, x_mask, y_mask)
    f = im2double(f);
    g = zeros(size(f));
    for i = 2:1:size(f,1)-1
        for j = 2:1:size(f,2)-1
            mask = f(i-1:i+1,j-1:j+1);
            gx = sum(sum(mask .* x_mask)).^2;
            gy = sum(sum(mask .* y_mask)).^2;
            t = sqrt(gx + gy);
            if (t > T)
                g(i,j) = 1;
            end
        end
    end
end