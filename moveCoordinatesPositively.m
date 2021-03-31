function [moved_coordinates, margin] = moveCoordinatesPositively(course_x, course_y)
    % ------------------正の整数にするためにマージンをとる---------------- %
    min_x = min(course_x);
    min_y = min(course_y);
    if min_x < 0
        margin_x = linspace(abs(min_x), abs(min_x), length(course_x));
        course_x = course_x + margin_x;
    end
    if min_y < 0
        margin_y = linspace(abs(min_y), abs(min_y), length(course_y));
        course_y = course_y + margin_y;
    end

    moved_coordinates = [course_x; course_y];
    margin = [min_x, min_y];

end