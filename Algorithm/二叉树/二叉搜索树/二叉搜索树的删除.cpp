#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteMin(TreeNode* root){
        //删除BST中的最小的节点
        if(root->left == nullptr) //当left为空时，就返回他的右节点，root节点就被删除了
            return root->right;
        root->left = deleteMin(root->left); //否则不断深入左子树,直到left为空
        return root;
    }

    TreeNode* min(TreeNode* root){
        if(root->left == nullptr)
            return root;
        return min(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);

        else{
            //两个都为nullptr返回的就是nullptr
            if(root->right == nullptr)
                return root->left;
            if(root->left == nullptr)
                return root->right;
            
            //后继节点是右子树的最小节点（或者左子树的最大节点）
            //找到右子树的最小节点
            TreeNode* cur = root;
            root = min(cur->right);
            // //修改root的值（这样的操作不够高效，一般通过指针的链接来避免修改值）
            // root->val = cur->val;
            // //转去删除那个后继节点
            // root->right = deleteNode(root->right, cur->val);
            root->right = deleteMin(cur->right);
            root->left = cur->left;
            
        }
        return root;
    }
};