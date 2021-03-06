class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int found = 0;
        auto res = dfs(root, p, q, found);
        if (found==2) {
            return res;
        } else {
            return nullptr;
        }
    }
    
    TreeNode* dfs(TreeNode* cur, TreeNode* p, TreeNode* q, int& found) {
        if (cur==nullptr) {
            return nullptr;
        }

        
        auto node1 = dfs(cur->left, p, q, found);
        auto node2 = dfs(cur->right, p, q, found);
        
        if (cur==p || cur==q) {
            found++;
            return cur;
        }
        
        if (node1!=nullptr && node2!=nullptr) {
            return cur;
        } else if (node1!=nullptr) {
            return node1;
        } else if (node2!=nullptr) {
            return node2;
        } else {
            return nullptr;
        }
    }
};
