function [ref_x, ref_y] = searchRefNode(open_list)     
    scores = zeros(1, length(open_list));

    for i = 1 : length(open_list)
        scores(i) = open_list(i).score;
    end

    minimum = min(min(scores));
    index = find(scores == minimum); % 最小スコアのインデックスを取得

    ref_x = open_list(index).x;
    ref_y = open_list(index).y;

end