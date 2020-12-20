/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right!=nullptr) {
            auto cur = p->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            return cur;
        }
        
        TreeNode* node = root;
        TreeNode* res = nullptr;
        while (node != p) {
            if (p->val < node->val) {
                res = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return res;
        
    }
};
