func findDistance(root *TreeNode, p int, q int) int {
    d1, d2 := dfs(root, p, q)
    return d1+d2
}

func dfs(cur *TreeNode, p int, q int) (int, int) {
    if (cur==nil) {return -1,-1 }
    dp1, dq1 := dfs(cur.Left, p, q)
    dp2, dq2 := dfs(cur.Right, p, q)
    if (dp1!=-1 && dq1!=-1) {
        return dp1, dq1
    }
    if (dp2!=-1 && dq2!=-1) {
        return dp2, dq2
    }
    res_p := -1
    res_q := -1
    
    if (dp1!=-1) {
        res_p = dp1
    } 
    if (dp2!=-1) {
        res_p = dp2
    } 
    if (dq1!=-1) {
        res_q = dq1
    }
    if (dq2!=-1) {
        res_q = dq2
    }
    
    if (res_p!=-1) {
        res_p++
    }
    if (res_q!=-1) {
        res_q++
    }
    if (cur.Val==p) {
        res_p = 0     
    } 
    if (cur.Val==q) {
        res_q = 0
    }
    
    return res_p, res_q
} 
