
  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else if(val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->val = val;
        return root;
    }
};