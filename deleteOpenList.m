function return_open_list = deleteOpenList(open_list, ref_x, ref_y)
    for i = 1 : length(open_list)
        if open_list(i).x == ref_x && open_list(i).y == ref_y
            open_list(i) = [];
            break;
        end
    end
    
    return_open_list = open_list;
end