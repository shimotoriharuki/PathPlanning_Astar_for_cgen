function plotMap(map)

sizes = size(map);
size_x = sizes(1, 2);
size_y = sizes(1, 1);
image_data = zeros(size_y, size_x, 3);

for x = 1 : size_x
    for y = 1 : size_y
       if map(y, x).obstacle == 0
           image_data(y, x, 1) = 255;
           image_data(y, x, 2) = 255;
           image_data(y, x, 3) = 255;
       end
    end
end
        
image(image_data);
axis equal

end