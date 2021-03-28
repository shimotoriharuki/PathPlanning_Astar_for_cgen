function [return_map, return_open_list] = openAroundNodeDP(map, open_list, ref_x, ref_y, cost_table, size_x, size_y, goal) %Diagonal prohibition
    for i = [0, -1, 1, 0]
        x = ref_x + i;
        if x < 1
            continue;
        elseif x > size_x
            continue;
        end

        for j =  -1 : 1
            if i ~= 0
                y = ref_y;
            else
                y = ref_y + j;
            end

            if y < 1
                continue;
            elseif y > size_y
                continue;
            end

            if map(y, x).obstacle == 0 && map(y, x).status == 0 && ~(ref_x == x && ref_y == y) % 移動可能 かつ 状態がNone かつ 基準ノードでない
                map(y, x).status = uint16(1); % open
                direction_cost = cost_table(j + 2, i + 2);
                map = calcScore(map, x, y, map(ref_y, ref_x).g_cost, direction_cost, goal); % コストを計算

                temp_node.x = x;
                temp_node.y = y;
                temp_node.score = map(y, x).score;
                temp_node.g_cost = map(y, x).g_cost;
                temp_node.h_cost = map(y, x).h_cost;
%                 open_list = [open_list, temp_node]; %オープンリストに追加

                temp_open_list = zeros(1, length(open_list));
                for k = 1 : length(open_list)
                    temp_open_list(k) = open_list(k).x;
                end
                index = find(temp_open_list < 0, 1);
%                 index = min(index);
                open_list(index) = temp_node;
%                 disp(open_list(2));
%                 for index = 1 : length(open_list)
%                     if open_list(index).x == -1
%                         open_list(index) = temp_node;
%                         break;
%                     end
%                 end


                map(y, x).parent = [uint16(ref_x),uint16(ref_y)]; %親ノードの位置を保存
            end

            map(ref_y, ref_x).status = uint16(2); %基準ノードをクローズ
            open_list = deleteOpenList(open_list, ref_x, ref_y); %オープンリストからクローズした基準ノードを削除
                   
        end
        
    end
    return_map = map;
    return_open_list = open_list;

end