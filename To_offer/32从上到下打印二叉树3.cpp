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
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
*/

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
                if(level % 2 == 0)
                    res[level].push_back(tmp->val);
                else
                    res[level].insert(res[level].begin(), tmp->val);
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