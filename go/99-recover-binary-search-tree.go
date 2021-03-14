/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func swap(x, y *TreeNode) {
    x.Val, y.Val = y.Val, x.Val
}

func recoverTree(root *TreeNode)  {
    _, _, swap1, swap2 := dfs(root)
    swap(swap1, swap2)
}


func dfs(node *TreeNode) (*TreeNode, *TreeNode, *TreeNode, *TreeNode) {
    if (node==nil) {
        return nil, nil,nil,nil
    }
    
    l1, l2, ls1, ls2  := dfs(node.Left)
    r1, r2, rs1, rs2 := dfs(node.Right)
    
    var swap1, swap2 *TreeNode
    if (l2!=nil && r1!=nil && l2.Val>r1.Val) {
        swap1 = l2
        swap2= r1
    } else if (l2!=nil && node != nil && l2.Val > node.Val) {
        swap1 = l2
        swap2 = node
    } else if (node!=nil && r1!=nil && node.Val > r1.Val) {
        swap1 = node
        swap2 = r1
    } else {
        if (ls1 !=nil) {
            swap1 = ls1
            swap2 = ls2
        } else {
            swap1 = rs1
            swap2 = rs2
        }
    }
    
    min := node
    if (l1!=nil && l1.Val<min.Val) {
        min = l1
    }
    if (r1!=nil && r1.Val<min.Val) {
        min = r1
    }
    max := node
    if (l2!=nil && l2.Val>max.Val) {
        max = l2
    }
    if (r2!=nil && r2.Val>max.Val) {
        max = r2
    }
    return min,max,swap1, swap2
}
