function shortcut_course = generateShortcutPath(src_course, range)
    % ------------------正の整数にするためにマージンをとる---------------- %
    [course, margin] = moveCoordinatesPositively(src_course(1, :), src_course(2, :));

    goal_x = course(1, end) + 1;
    goal_y = course(2, end) + 1;

    % 必要なマップのサイズを調べる
    size_x = max(course(1, :)) - min(course(1, :)) + 1; % xのベクトルの最大値-最小値でマップのx方向サイズを計算 
    size_y = max(course(2, :)) - min(course(2, :)) + 1; % yのベクトルの最大値-最小値でマップのy方向サイズを計算

    remaining_course = course;
    shortcut_course = repmat(-1, 2, 9999);
    
    while 1
        % コースを交差点で切る
        flag_table = getFlagTable(remaining_course, 10, 10);
        [trimming_course, remaining_course] = courseTrimer(remaining_course, flag_table);

        % マップを作成する
        expantion = round(range); %cm 膨張させる大きさ
        map = createMap(size_x, size_y, trimming_course, expantion); %バイナリマップ

        % 最短経路を計算
        start = [trimming_course(1, 1) + 1; trimming_course(2, 1) + 1];
        goal = [trimming_course(1, end) + 1; trimming_course(2, end) + 1];

        [store_course] = computeAstar(map, start, goal, size_x, size_y);

        % 切り取られたコースを連結する
        index = find(shortcut_course(1, :) < 0, 1);
        for k = 0 : length(store_course(1, :)) - 1
            shortcut_course(:, index + k) = store_course(:, k+1);
        end
        
        % ゴールに着いたら処理を終了
        if trimming_course(1, end) == goal_x - 1 && trimming_course(2, end) == goal_y - 1
            break;
        end
    end
      
    end_index = find(shortcut_course(1, :) < 0, 1);
    end_indexx = end_index(1, 1);
    shortcut_course(:, end_indexx : end) = repmat(shortcut_course(:, end_indexx - 1), 1, length(shortcut_course(:, end_indexx : end))); %使ってない要素を最後のコース情報で埋める
    
    ones_matrix = ones(2, length(shortcut_course(1, :)));    
    shortcut_course = shortcut_course - ones_matrix; %行列のインデックスにするために1を足していたのを引く
    
    shortcut_course = removeMargin(shortcut_course, margin); % 正にマージンしていた分を取り除く
     
    shortcut_course = getMovingAverage(shortcut_course, 30); % 平滑化のため移動平均を計算
    
end