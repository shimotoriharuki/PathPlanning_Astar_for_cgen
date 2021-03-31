function return_course = removeMargin(course, margin)

    margin_x = linspace(abs(margin(1)), abs(margin(1)), length(course(1, :)));
    margin_y = linspace(abs(margin(2)), abs(margin(2)), length(course(2, :)));
    
    course(1, :) = course(1, :) - margin_x;
    course(2, :) = course(2, :) - margin_y;
    
    return_course = course;
end