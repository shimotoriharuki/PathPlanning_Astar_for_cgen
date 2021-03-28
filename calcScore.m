function returnMap = calcScore(map, x, y, g_cost, direction_cost, goal)
%    map(y, x).g_cost = g_cost + 1 + direction_cost;
    map(y, x).g_cost = g_cost + 1;
%    map(y, x).g_cost = 0;

%    map(y, x).h_cost = abs(obj.goal_x - x) + abs(obj.goal_y - y);
    map(y, x).h_cost = sqrt(power(goal(1, 1) - x, 2) + power(goal(2, 1) - y, 2));
%   map(y, x).h_cost = 0;
    map(y, x).score = map(y, x).g_cost + map(y, x).h_cost;
    
    returnMap = map;
end