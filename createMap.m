function map = createMap(size_x, size_y, course_data, expantion)
    node.obstacle = uint16(1);
    node.status = uint16(0);
    node.g_cost = uint16(0);
    node.h_cost = uint16(0);
    node.score = uint16(0);
    node.g_cost = uint16(0);
    node.parent = [uint16(0),  uint16(0)];

    empty_map = repmat(node, size_y, size_x); % 行、列　＝　y, x

    x_datas = course_data(1, :);
    y_datas = course_data(2, :);
    half_expantion = round(expantion / 2);
    
    for i = 1 : length(x_datas)
        for ex = 1 : expantion
            for ey = 1 : expantion
                x = x_datas(i) + 1 - half_expantion + ex;
                y = y_datas(i) + 1 - half_expantion + ey;

                if x < 1
                   x = 1; 
                elseif x > size_x
                    x = size_x;
                end
                if y < 1
                   y = 1; 
                elseif y > size_y
                    y = size_y;
                end

                empty_map(y, x).obstacle = uint16(0);
            end
        end
    end

    map = empty_map;

end