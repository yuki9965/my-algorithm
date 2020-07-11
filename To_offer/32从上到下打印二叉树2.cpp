#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<vector<int>> res;
        queue<TreeNode* > q;

        int level = 0;
        q.push(root);

        while(!q.empty()){
            if(res.size() <= level){
                res.push_back({});
            }
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode* tmp = q.front();
                res[level].push_back(tmp->val);
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            level++;
        }
        return res;
    
    }
};
