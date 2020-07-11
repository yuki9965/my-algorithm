#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]
*/
class Solution {
public:
    
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode* > q;
        if(root == nullptr)
            return {};
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            res.push_back(tmp->val);
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        return res;
    }
};