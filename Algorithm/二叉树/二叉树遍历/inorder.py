# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
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
                s.append((0, t.right))
                s.append((1, t))
                s.append((0, t.left))
            else:
                res.append(t.val)
        return res
                
                
       
        