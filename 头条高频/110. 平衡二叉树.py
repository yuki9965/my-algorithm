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
    bool isBalanced(TreeNode* root) {
        int height;
        return balanceHeight(root, height) ;
    }
    int balanceHeight(TreeNode *root, int& height){
        if(root == nullptr){ //递归基
            height = -1;
            return true;
        }
        int left, right;
        if(balanceHeight(root->left, left) &&
            balanceHeight(root->right, right) &&
            abs(left - right) <= 1){
                height = max(left, right) + 1;
                return true;
            } 
        return false;
    }
};