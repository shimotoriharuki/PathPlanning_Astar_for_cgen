% 前処理 master
clc
% close all
clf
clear

% --------------コースデータ用意-----------------%
% course_x = round(linspace(-1, 10, 10));
% course_y = [0, 1, 2, 3, 4, 4, 4, 3, 2, 1];

% course_x = round(1 : 1 : 20); %cm
% course_y = round(-sin(course_x/10) * 20); %cm

% course_x = [0, 1, 2, 3, 4, 5];
% course_y = [0, 0, 1, 1, 2, 2];

% num = linspace(0, 1 * pi, 100);
% course_x = round(sin(num) * 50); %cm
% course_y = round(cos(num) * 50); %cm

% num = linspace(0, 0.5 * pi, 500);
% course_x = round(sin(num) * 20); %cm
% course_y = round(sin(2 * num) * 20); %cm

% num = linspace(0, 0.3 * pi, 100);
% course_x = round(sin(1 * num) * 10); %cm
% course_y = round(sin(4 * num) * 8); %cm

fileName = 'course_data/2019AllJapan.txt';
positions = readmatrix(fileName); %[m}
positions = positions .* 100; %cm
course_x = round(positions(:, 1)');
course_y = round(positions(:, 2)');

% 最短経路を計算
course = [course_x; course_y];
% shortcut_course = generateShortcutPath(course);
shortcut_course = generateShortcutPath_mex(course);

figure(1)
scatter(course_x, course_y)
title('コース元データ')
xlabel('x')
ylabel('y')
axis equal

figure(2)
hold on
scatter(course(1, :), course(2, :), '*', 'b')
title('マージンしたコースデータ')
xlabel('x')
ylabel('y')
axis equal

scatter(shortcut_course(1, :), shortcut_course(2, :), 'o')
title('ショートカット')
xlabel('x')
ylabel('y')
axis equal

% scatter(ave_course(1, :), ave_course(2, :), '+')
% title('移動平均')
% xlabel('x')
% ylabel('y')
% axis equal
% hold off

% for i = 1 : 5
% while map.goal_x ~= goal_x || map.goal_y ~= goal_y
    % --------------交差しているところでコースデータを切る --------%
%     [trimming_course, remaining_course] = courseTrimer(remaining_course, 10, 20);

    % -------------------マップ作成--------------------%
%     map = Map(course, trimming_course, expantion); %バイナリマップ

%     figure(3)
%     heatmap(map.binary_grid)
%     title('バイナリマップ')
%     xlabel('x')
%     ylabel('y')


    % 最短経路計算計算
%     [shortcut_course] = computeAstar(map);

%     figure(4)
%     heatmap(map.shorter_path_grid)

%     figure(5)
%     hold on
%     scatter(course(1, :), course(2, :), '*', 'b')
%     title('マージンしたコースデータ')
%     xlabel('x')
%     ylabel('y')
%     axis equal

%     ones_matrix = ones(2, length(shortcut_course(1, :)));
%     shortcut_course = shortcut_course - ones_matrix; %行列のインデックスにするため、1を足していたのを引く
    
%     scatter(shortcut_course(1, :), shortcut_course(2, :), 'o')
%     title('ショートカット')
%     xlabel('x')
%     ylabel('y')
%     axis equal
%     hold off

% end














