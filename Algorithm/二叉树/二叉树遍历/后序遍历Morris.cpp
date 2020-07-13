
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> res;

    void PrintEdge(TreeNode* root)
    {
        TreeNode* tail = ReverseEdge(root);
        TreeNode* cur = tail;
        while(cur != nullptr)
        {
            res.push_back(cur->val);
            cur = cur->right;
        }
        ReverseEdge(tail);
    }

    TreeNode* ReverseEdge(TreeNode* from)
    {
        TreeNode* pre = nullptr;
        TreeNode* next = nullptr;
        while(from != nullptr)
        {
            next = from->right;
            from->right = pre;
            pre = from;
            from = next;
        }
        return pre;
    }

    vector<int> inorderTraversal(TreeNode* root){
        TreeNode *cur = root, *prev = nullptr;
        while(cur != nullptr){
            prev = cur->left;

            if(prev == nullptr){
                res.push_back(cur->val);
                cur = cur->right; //这里会转到它的后驱节点
            }
            else{
                //找到cur的前驱节点，就是左子树的最右节点
                while(prev->right != nullptr && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == nullptr){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = nullptr;
                    //res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};