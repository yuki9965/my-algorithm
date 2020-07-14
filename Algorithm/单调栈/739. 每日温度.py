class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        stack = list()
        t_length = len(T)
        res_list = [0 for _ in range(t_length)]
        
        for key, value in enumerate(T):             
            while stack and T[stack[-1]] < value:
                res_list[stack[-1]] = key - stack[-1]
                stack.pop()
            stack.append(key)
        return res_list