function [trimming_course, remaining_course] = courseTrimer(course, flag_table)
    trimming_course = course;
    remaining_course = course;
    
    for i = 1 : length(flag_table)
        if flag_table(i) == 1
            trimming_course = [course(1, 1 : i); course(2, 1 : i)];
            remaining_course = [course(1, i + 1 : end); course(2, i + 1 : end)];
            break;
        end  
    end
      
end
