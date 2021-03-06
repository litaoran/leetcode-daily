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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return dfs(pre, 0, n-1, post, 0, n-1);
    }
    
    TreeNode* dfs(vector<int>& pre, int l1, int r1, vector<int>& post, int l2, int r2) {
        if (l1>r1) {return nullptr;}
        if (l1==r1) {return new TreeNode(pre[l1]);}
        
        TreeNode* node = new TreeNode(pre[l1]);
        
        
        unordered_set<int> s1;
        unordered_set<int> s2;
        int i = 1;
        while (i+l1<=r1) {
            int cur1 = pre[i+l1];
            if (s2.count(cur1) !=0) {
                s2.erase(cur1);
            } else {
                s1.insert(cur1);
            }
            
            int cur2 = post[l2+i-1];
            if (s1.count(cur2) !=0) {
                s1.erase(cur2);
            } else {
                s2.insert(cur2);
            }
            
            if (s1.empty() && s2.empty()) {
                break;
            }
            i++;
        }
        node->left = dfs(pre, l1+1, i+l1, post,l2,l2+i-1);
        node->right = dfs(pre, i+l1+1, r1, post, l2+i, r2-1);

        
        return node;
    }
};
