function return_open_list = deleteOpenList(open_list, ref_x, ref_y)
    for i = 1 : length(open_list)
        if open_list(i).x == ref_x && open_list(i).y == ref_y
            init_node.x = -1;
            init_node.y = -1;
            init_node.score = uint16(9999);
            init_node.g_cost = uint16(9999);
            init_node.h_cost = uint16(9999);
            open_list(i) = init_node;
            break;
        end
    end
    
    return_open_list = open_list;
end