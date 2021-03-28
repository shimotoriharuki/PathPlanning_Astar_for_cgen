function ret = createMapCgenTest()
    node.obstacle = uint16(0);
    node.status = uint16(0);
    node.parent = uint8([0, 0]);
    
    ret = repmat(node, 3, 3);
end