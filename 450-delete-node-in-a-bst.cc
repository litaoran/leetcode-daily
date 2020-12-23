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
    
    TreeNode* parent = nullptr;
    TreeNode* find(TreeNode* node, int key) {
        if (node==nullptr) {return nullptr;}
        
        if (node->val == key) {
            return node;
        } else {
            parent = node;
            if (key< node->val) {
                return find(node->left, key );
            } else {
                return find(node->right, key);
            }
        }
    }
    
    TreeNode* FindNext(TreeNode* parent, TreeNode* left_child) {
        if (left_child->left==nullptr) {
            parent->left = left_child->right;
            return left_child;
        }
        
        return FindNext(parent->left, left_child->left);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr) {return nullptr;}
        
        TreeNode* node = find(root, key);
        if (node == nullptr) {return root;}
        cout << node->val;
        
        TreeNode* new_node = nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            new_node = nullptr;
        } else if (node->left == nullptr) {
            new_node = node->right;
        } else if (node->right == nullptr) {
            new_node = node->left;
        } else {
            if (node->right->left==nullptr) {
                new_node = node->right;
                new_node->left = node->left;
            } else {
                new_node = FindNext(node->right, node->right->left);
                new_node->left = node->left;
                new_node->right = node->right;
            }   
        }
        
        if (parent==nullptr) {
            root = new_node;
        } else {
            if (parent->left == node) parent->left = new_node; 
            if (parent->right == node) parent->right = new_node; 
        }
        
        return root;   
    }
};
