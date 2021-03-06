func lowestCommonAncestor(p *Node, q *Node) *Node {
    var l1 []*Node
    var l2 []*Node
    node1 := p
    node2 :=
    for (node1!= nil) {
        l1 = append(l1, node1)
        node1 = node1.Parent
    }
    
    for (node2 != nil) {
        l2 = append(l2, node2)
        node2 = node2.Parent
    }
     
    idx1 := len(l1)-1
    idx2 := len(l2)-1
    
    var res *Node = nil
    for (idx1>=0 && idx2>=0) {
        if (l1[idx1]==l2[idx2]) {
            res = l1[idx1]       
        } else {
            break
        }
        idx1--
        idx2--
    }
    return res
}
