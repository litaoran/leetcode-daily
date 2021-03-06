class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> set(nodes.begin(), nodes.end());    
        return dfs(root, set);
    }
    
    TreeNode* dfs(TreeNode* cur, unordered_set<TreeNode*> set) {
        if (cur==nullptr) { return nullptr;}
        if (set.count(cur)!=0) { return cur; }
        
        auto node1 = dfs(cur->left, set);
        auto node2 = dfs(cur->right, set);
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
