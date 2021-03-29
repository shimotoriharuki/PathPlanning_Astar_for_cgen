function ret = createMapCgenTest()
    node.obstacle = NaN;
    node.status =  NaN;
    node.parent = NaN;
    
    ret = repmat(node, 3, 3);
end