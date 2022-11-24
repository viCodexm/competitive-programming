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
    TreeNode* ans;
    
    Solution() {
        this->ans = NULL;
    }
    
    bool rec(TreeNode* current, TreeNode* p, TreeNode* q) {
        if (current == NULL) {
            return false;
        }
        bool left = rec(current->left, p, q);
        bool right = rec(current->right, p, q);
        bool mid = false;
        if (current == p || current == q)
            mid = true;
        
        if (left + right + mid >= 2)
            this->ans = current;
        
        return (left + right + mid > 0);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->rec(root, p, q);
        return this->ans;
    }
};