function average_course = getMovingAverage(src_course, range)
    m_x = movmean(src_course(1, :), range);
    m_y = movmean(src_course(2, :), range);
    
    average_course = [m_x; m_y];

end