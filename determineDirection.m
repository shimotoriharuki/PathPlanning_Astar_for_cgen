function direction = determineDirection(x, y, pre_x, pre_y)
            
    dx = x - pre_x;
    dy = y - pre_y;

    if dx > 0 && dy > 0
        direction = 'rb';
    elseif dx == 0 && dy > 0
        direction = 'b';
    elseif dx < 0 && dy > 0
        direction = 'lb';
    elseif dx < 0 && dy == 0
        direction = 'l';
    elseif dx < 0 && dy < 0
        direction = 'lu';
    elseif dx == 0 && dy < 0
        direction = 'u';
    elseif dx > 0 && dy < 0
        direction = 'ru';
    elseif dx > 0 && dy == 0
        direction = 'r';
    end

%             if dx == 0 && dy > 0
%                 direction = 'b';
% 
%             elseif dx < 0 && dy == 0
%                 direction = 'l';
% 
%             elseif dx == 0 && dy < 0
%                 direction = 'u';
% 
%             elseif dx > 0 && dy == 0
%                 direction = 'r';
%             else
%                 direction = 'a'; % around
%             end

end