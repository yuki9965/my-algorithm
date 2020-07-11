#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;
        if(A != nullptr && B != nullptr){
            if(A->val == B->val)
                res = TreeAHasTreeB(A, B);
            if(!res)
                res = isSubStructure(A->left, B);
            if(!res)
                return isSubStructure(A->right, B);
        }
        return res;
    }


    bool TreeAHasTreeB(TreeNode* A, TreeNode* B){
        if(B == nullptr)
            return true;
        if(A == nullptr)
            return false;
        if(A->val != B->val)
            return false;
        else
            return TreeAHasTreeB(A->left, B->left) && TreeAHasTreeB(A->right, B->right);
    }


};