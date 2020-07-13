class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(0, root));
        while(!s.empty())
        {
            int f = s.top().first;
            TreeNode* t = s.top().second;
            s.pop();
            if(t == nullptr)
                continue;
            if(f == 0) //未被访问过
            {
                s.push(make_pair(1, t));
                s.push(make_pair(0, t->right));
                s.push(make_pair(0, t->left));
            }
            else
                res.push_back(t->val);
        }
        return res;
    }
};

def postorderTraversal(root):
    res = []
    s = []
    s.append((0, root))
    while s:
        f = s[-1][0]
        t = s[-1][1]
        s.pop()
        if not t:
            continue
        if f == 0:
            s.append((1, t))
            s.append((0, t.right))
            s.append((0, t.left))
        else:
            res.append(t.val)
    return res