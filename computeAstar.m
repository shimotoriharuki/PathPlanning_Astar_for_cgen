function shortcut_course = computeAstar(map, start, goal, size_x, size_y)
    % % -----------A star開始------------ %
    x = start(1, 1);
    y = start(2, 1);

    cost_table = [0, 0, 0;
                  0, 0, 0;
                  0, 0, 0];

    init_node.x = -1;
    init_node.y = -1;
    init_node.score = uint16(9999);
    init_node.g_cost = uint16(9999);
    init_node.h_cost = uint16(9999);
    open_list = repmat(init_node, 1, 999);
    [map, open_list] = openAroundNodeDP(map, open_list, x, y, cost_table, size_x, size_y, goal); % スタートノードの周りをオープン

    count = 0;
    while x ~= goal(1, 1) || y ~= goal(2, 1)

        [x, y] = searchRefNode(open_list); % スコアが最も小さいノードのx, yを得る
        [map, open_list] = openAroundNodeDP(map, open_list, x, y, cost_table, size_x, size_y, goal);

        count = count + 1;

    end


    % % -----------最短経路の座標を取得------------ %
    store_x = zeros(1, 9999);
    store_y = zeros(1, 9999);
    cnt = 1;
    while x ~= start(1, 1) || y ~= start(2, 1)
        temp_xy = map(y, x).parent;
        x = double(temp_xy(1));
        y = double(temp_xy(2));

        store_x(cnt) = x;
        store_y(cnt) = y;
        cnt = cnt + 1;
    end

    shortcut_course = [flip(store_x(1 : cnt - 1)); flip(store_y(1 : cnt - 1))];% 順序が逆なのでflipでもとに戻す
end