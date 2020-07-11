#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;



 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int start, int end){// 中序的start和end
        if(start > end) return NULL;
        TreeNode *tree = new TreeNode(preorder[root]);
        int i = start;
        while(i < end && preorder[root] != inorder[i]) i++;
        tree->left = build(preorder, inorder, root + 1, start, i - 1);
        tree->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);
        return tree;
    }
};