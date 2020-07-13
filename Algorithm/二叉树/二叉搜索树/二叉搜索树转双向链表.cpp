#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
private:
    /* data */
    Node *pre;
    Node *head;
    Node *tail;

public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        helper(root);
        //连接首尾
        head->left = tail;
        tail->right = head;
        return head;
    }

    void helper(Node* root){
        if(root == nullptr)
            return;
        helper(root->left); //中序遍历操作

        root->left = pre;
        if(pre == nullptr)  //说明root此时是头结点
            head = root;
        else
            pre->right = root;

        pre = root;     

        tail = root;

        helper(root->right);
    }
};

