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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode *root, long lower, long upper){
        if(root == nullptr) return true;
        return root->val > lower && root->val < upper
            && isValidBST(root->left, lower, root->val)
            && isValidBST(root->right, root->val, upper);
    }
};