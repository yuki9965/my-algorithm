# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stack = []
        stack.append((0, root))
        while stack:
            color = stack[-1][0]
            node - stack[-1][1]
            stack.pop()
            if not node:
                continue
            if color == 0:  # 未被访问过
                stack.append((0, node.right))
                stack.append((0, node.left))
                stack.append((1, node))
            else:
                res.append(node.val)
        return res