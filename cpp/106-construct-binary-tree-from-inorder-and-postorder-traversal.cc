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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder will always be split into two subtrees from the middle.
        int n = inorder.size();
        return dfs(inorder, 0, n-1, postorder, 0, n-1);
    }
    
    TreeNode* dfs(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2) {
        if (l1>r1) {
            return nullptr;
        }
        if (l1==r1) {
            return new TreeNode(postorder[r2]);
        }
        
        int val = postorder[r2]; 
        
        auto it = find(inorder.begin()+l1, inorder.begin()+r1, val);
        int mid = it - inorder.begin();
        
        int left_size = mid-l1;  // how many nodes in the left subtree
        int right_size = r2-mid; // how many nodes in the right subtree
        
        
        TreeNode* node = new TreeNode(val);
        
        node->left = dfs(inorder, l1, mid-1, postorder, l2, l2+left_size-1);
        node->right = dfs(inorder, mid+1, r1, postorder, l2+left_size, r2-1);
        
        return node;
    }
};
