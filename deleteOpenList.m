function return_open_list = deleteOpenList(open_list, ref_x, ref_y)
    for i = 1 : length(open_list)
        if open_list(i).x == ref_x && open_list(i).y == ref_y
            init_node.x = -1;
            init_node.y = -1;
            init_node.score = uint16(9999);
            init_node.g_cost = uint16(9999);
            init_node.h_cost = uint16(9999);
            
            if i == 1 % 配列の最初だったら、初期化してシフトして一番うしろに持っていく
                open_list(i) = init_node;
                open_list = circshift(open_list, -1);
                
            elseif i == length(open_list) % 配列の最後だったら初期化だけする
                open_list(i) = init_node;
                
            else % その他は対象のやつを初期化して後ろに持っていく
%                 open_list(i) = init_node;
                
                temp_list = repmat(init_node, 1, length(open_list));                
                temp_list(1 : i - 1) = open_list(1 : i - 1);
                temp_list(i : end - 1) = open_list(i + 1 : end);
%                 temp_list(end) = init_node;
                
                open_list = temp_list;
                
%                 first = open_list(1 : i - 1);
%                 last = open_list(i : end);
%                 last = circshift(last, -1);
                
%                 open_list = horzcat(first, last);
            end
            break;
            
        end
    end
    
    return_open_list = open_list;
end