class Solution:
    def isValid(self, s: str) -> bool:
       
        """
        括号匹配
        :type s: str
        :rtype: bool
        """
        parents = {k: v for k, v in zip('([{', ')]}')}
        stack = []
        for char in s:
            if char in parents.keys() or char in parents.values():
                if char in parents:
                    stack.append(char)
                elif not stack or parents[stack.pop()] != char:
                    return False
        return not stack