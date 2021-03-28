function [ref_x, ref_y] = searchRefNode(open_list)     
    scores = zeros(1, length(open_list));

    for i = 1 : length(open_list)
        scores(i) = open_list(i).score;
    end

    minimum = min(min(scores));
    index = find(scores == minimum); % 最小スコアのインデックスを取得

    if length(index) > 1 %最小のコストが複数あったら
%           disp('HERE')
        min_cost = 99999;
        min_index = [];
        for j = index
%           disp(num2str(open_list(j).x));
%           disp(num2str(open_list(j).y));

            if open_list(j).g_cost < min_cost
                min_cost = open_list(j).g_cost;
                min_index = j;
            end
        end     
    else 
%        disp('here')
        min_index = index;
    end

    ref_x = open_list(index).x;
    ref_y = open_list(index).y;

end