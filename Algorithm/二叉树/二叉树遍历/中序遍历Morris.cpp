#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> inorderTraversal(TreeNode* root){
    TreeNode *cur = root, *prev = nullptr;
    vector<int> res;
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
                //前序遍历的cout放在这里，其他都和中序一样
                //res.push_back(cur->val);
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return res;
}

class Solution {
	vector<int>ans;

public:

	vector<int> inorderTraversal(TreeNode* root) {
		int white = 0;
		int gray = 1;
		stack<pair<int, TreeNode*>>s;
		s.push(make_pair(white,root));
		while (!s.empty())
		{
			int color = s.top().first;
			TreeNode* t = s.top().second;
			s.pop();
			if (t == NULL) continue;
			if (color == white)
			{
				s.push(make_pair(white, t->right));
				s.push(make_pair(gray, t));
				s.push(make_pair(white, t->left));
			}
			else ans.push_back(t->val);
		}
		return ans;
	}
};