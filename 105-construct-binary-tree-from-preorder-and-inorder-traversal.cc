/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {return nullptr;}
    
        int n = inorder.size();
        unordered_map<int, int> map;
        for (int i=0;i<n;i++) {
            map.insert({inorder[i], i});
        }
        
        return dfs(preorder, 0, n-1, inorder, 0, n-1, map);
    }
    
    TreeNode* dfs(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2, unordered_map<int, int>& map) {
        if (l1>r1) {
            return nullptr;
        }
        if (l1==r1) {
            return new TreeNode(preorder[l1]);
        }
        
        int root_val = preorder[l1];
        int i_idx = map[root_val];
        
        int left_size = i_idx - l2;
        int right_size = r2 - i_idx;
        
        auto* cur_node = new TreeNode(preorder[l1]);
        cur_node->left = dfs(preorder, l1+1 , l1+left_size, inorder, l2, i_idx-1, map);
        cur_node->right = dfs(preorder, l1+left_size+1, r1, inorder, i_idx+1, r2, map);
        
        return cur_node;
    }
};
