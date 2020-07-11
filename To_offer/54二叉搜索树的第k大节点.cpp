#include<vector>
#include<iostream>
using namespace std;
/*
给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int ans;
    int count = 0;
    int kthLargest(TreeNode* root, int k) {
        Morder(root, k);
        return ans;
    }

    void Morder(TreeNode* root, int k){
        if(root->right != nullptr) //因为从大到小 所以和普通中序遍历是反着的
            Morder(root->right, k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        if(root->left != nullptr)
            Morder(root->left, k);
    }
};