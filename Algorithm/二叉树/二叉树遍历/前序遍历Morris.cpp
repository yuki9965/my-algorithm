#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root){
    TreeNode* cur = root, *prev = nullptr;
    vector<int> res;
    while(cur != nullptr){
        prev = cur->left;
        if(prev == nullptr){
            res.push_back(cur->val);
            cur = cur->right;
        }
        else{
            //前驱节点，左子树的最右节点
            while(prev->right != nullptr && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
}