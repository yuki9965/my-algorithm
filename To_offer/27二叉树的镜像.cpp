#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return pRoot;
        swap(pRoot->left, pRoot->right);
        if(pRoot->left)
            mirrorTree(pRoot->left);
        if(pRoot->right)    
            mirrorTree(pRoot->right);
        return pRoot;
    }
};