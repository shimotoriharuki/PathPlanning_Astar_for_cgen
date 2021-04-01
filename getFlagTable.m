function flag_table = getFlagTable(src_course, range, margin)
    flag_table = zeros(1, length(src_course));
    
    for i = 1 : length(src_course) % search_meginから検索することで、同じ交差点を検知することを防ぐ
        ref_position = [src_course(1, i); src_course(2, i)];
        diffs = zeros(2, length(src_course(1, :)));
        
        for j = 1 : length(src_course(1, :))
            diffs(1, j) = src_course(1, j) - ref_position(1, 1);
            diffs(2, j) = src_course(2, j) - ref_position(2, 1);
        end
%         diffs = src_course - ref_position;
        
        distances = sqrt(diffs(1, :).^2 + diffs(2, :).^2); % すべての点とref_positionとの距離を計算

        index = find(distances <= range); % 距離がrange以下だったインデックスを取得

        outlier = isoutlier(index); % 外れ値検知　外れ値があったら外れ値の位置に1がたつ
        total = sum(outlier, 'all'); % すべて足す
        flag = ge(total, 1); % 1以上（1つでも外れ値があったら）だったら交差している
        
        if flag == 1 % 交差点だったら
            flag_table(i) = 1;
        end       
    end
    
    % 白線を拡大した分、交差フラグをある程度前後に発生させる
    for i = 1 : length(flag_table) - 1 % 0から1か1から0に変わるところに2を置く
        if flag_table(i) ~= flag_table(i + 1)
            flag_table(i) = 2;
        end
    end
    
    for i = 1 : length(flag_table) % 2がある前後を1にする
        if flag_table(i) == 2
            for j = 1 : margin
                if flag_table(i - round(margin/2) + j) ~= 2
                    flag_table(i - round(margin/2) + j) = 1;
               end
            end
           flag_table(i) = 1;
        end
    end
    
    for i = 1 : length(flag_table) - 1 % 0から1か1から0に変わるところに3を置く
        if flag_table(i) ~= flag_table(i + 1)
            flag_table(i) = 3;
        end
    end
    
    % コースを分けるところだけ1にする
    for i = 1 : length(flag_table) 
        if flag_table(i) == 3
            flag_table(i) = 1;
        else
            flag_table(i) = 0;
        end
    end
end