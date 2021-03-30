function cost_table = getCostTable(x, y, pre_x, pre_y)    
    direction = determineDirection(x, y, pre_x, pre_y);

    if strcmp(direction, 'u') % 上
        cost_table = [-1, -1, -1;
                      1, 0, 1;
                      1, 1, 1];
    elseif strcmp(direction, 'ru') % 右上
        cost_table = [1, -1, -1;
                      1, 0, -1;
                      1, 1, 1];
    elseif strcmp(direction, 'r') % 右
        cost_table = [1, 1, -1;
                      1, 0, -1;
                      1, 1, -1];
    elseif strcmp(direction, 'rb') % 右下
        cost_table = [1, 1, 1;
                      1, 0, -1;
                      1, -1, -1];
    elseif strcmp(direction, 'b') % 下
        cost_table = [1, 1, 1;
                      1, 0, 1;
                       -1, -1, -1];
    elseif strcmp(direction, 'lb') % 左下
        cost_table = [1, 1, 1;
                      -1, 0, 1;
                      -1, -1, 1];
    elseif strcmp(direction, 'l') % 左
        cost_table = [-1, 1, 1;
                      -1, 0, 1;
                      -1, 1, 1];
    elseif strcmp(direction, 'lu') % 左上
        cost_table = [-1, -1, 1;
                      -1, 0, 1;
                      1, 1, 1];
    else
        cost_table = [1, 1, 1;
                      1, 0, 1;
                      1, 1, 1];
    end

end