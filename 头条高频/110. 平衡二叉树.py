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
        //用上一题的方法会重复计算
        //后序遍历时，左右孩子的高度我们都算过了，只要检查左右子树是不是平衡的
        return treeHeight(root) >= 0;
    }

    int treeHeight(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        if(left >= 0 && right >= 0 && abs(left - right) <= 1)
            return max(left, right) + 1;
        else
            return -1; //表示不平衡
    }
};