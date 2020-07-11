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

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0)
            return true;
        return verify(postorder, 0, postorder.size());
    }

    bool verify(vector<int>& postorder, int lo, int hi){
        if(lo >= hi)
            return true;
        int root = postorder[hi-1]; //最后那个是根节点
        //找到第一个大于root的节点
        int i = lo;
        for(; i < hi-1; ++i){
            if(postorder[i] > root)
                break;
        }
        //如果后面还有小于root的，一定不可能
        int j = i;
        for(; j < hi-1; ++j){
            if(postorder[j] < root)
                return false;
        }
        //递归判断左右子树
        bool left = true;
        if(i > lo)
            left = verify(postorder, lo, i-1);
        bool right = true;
        if(i < hi - 1)
            right = verify(postorder, i, hi-1);
        return (left && right);
    }
};