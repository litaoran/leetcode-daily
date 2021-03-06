func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    return dfs(root, p, q)
}

func dfs(cur, p, q *TreeNode) *TreeNode {
    if (cur==nil) {
        return nil
    }
    if (cur==p || cur == q) {
        return cur
    } 
    
    node1 := dfs(cur.Left, p, q)
    node2 := dfs(cur.Right, p, q)
    if (node1!=nil && node2!=nil) {
        return cur
    } else if (node1!=nil) {
        return node1
    } else if (node2!=nil) {
        return node2
    } else {
        return nil
    }
}
