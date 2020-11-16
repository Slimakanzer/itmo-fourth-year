f = imread('resources/gray.jpg');        
figure, imshow(f)
 
cr_array = zeros(12,1);
corr_array = zeros(12,1);
count_k = 1:12;
 
diagNumber = -5;
for i=1:12
    mask = ones(8);
    mask = triu(mask, diagNumber+i);
    mask = flip(mask, 2);
    
    f2 = im2jpeg(f, mask);
    d1 = im2double(f);          % compression ratio
    d2 = f2.code;               % compression ratio
    cr1 = whos('d1');           % compression ratio
    cr2 = whos('d2');           % compression ratio
    cr = cr1.bytes / cr2.bytes; % compression ratio
    f2 = jpeg2im(f2);
    corr = corr2(f, f2);
    

    cr_array(i) = cr;
    corr_array(i) = corr;
    count_k(i) = sum(sum(mask));
    figure, imshow(f2)
end

figure, plot(flip(corr_array), flip(count_k))
xlabel('Pirson correlation')
ylabel('Count')
 
figure, plot(flip(corr_array), flip(cr_array))
xlabel('Pirson correlation')
ylabel('Compression ratio')

