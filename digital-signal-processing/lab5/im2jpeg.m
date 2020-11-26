function y = im2jpeg(x, mask)
if nargin < 2
    mask = ones(8);
end

m = [16 11  10  16  24  40  51  61        
     12  12  14  19  26  58  60  55       
     14  13  16  24  40  57  69  56       
     14  17  22  29  51  87  80  62
     18  22  37  56  68  109 103 77
     24  35  55  64  81  104 113 92
     49  64  78  87  103 121 120 101
     72  92  95  98  112 100 103 99];
 
order = [1 9  2  3  10 17 25 18 11 4  5  12 19 26 33  ...
        41 34 27 20 13 6  7  14 21 28 35 42 49 57 50  ...
        43 36 29 22 15 8  16 23 30 37 44 51 58 59 52  ...
        45 38 31 24 32 39 46 53 60 61 54 47 40 48 55  ...
        62 63 56 64];
 
[xm, xn] = size(x);                
x = double(x) - 128;               
t = dctmtx(8);                     
y = blkproc(x, [8 8], 'P1 * x * P2', t, t');
y = blkproc(y, [8 8], 'round(x ./ P1)', m);
y = blkproc(y, [8 8], 'x .* P1', mask);
y = im2col(y, [8 8], 'distinct');  
xb = size(y, 2);                   
y = y(order, :);                   
eob = max(y(:)) + 1;               
r = zeros(numel(y) + size(y, 2), 1);
count = 0;
for j = 1:xb                       
   i = max(find(y(:, j)));         
   if isempty(i)                   
      i = 0;
   end
   p = count + 1;
   q = p + i;
   r(p:q) = [y(1:i, j); eob];      
   count = count + i + 1;          
end
r((count + 1):end) = [];
y           = struct;
y.size      = uint16([xm xn]);
y.numblocks = uint16(xb);
y.code      = r;
