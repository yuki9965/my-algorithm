class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        m = {}
        s = []
        # 记录nums2中，每个元素右边第一个大于它的值，并记录在m中
        for i in nums2:
            while s and s[-1] < i:
                m[s[-1]] = i
                s.pop()
            s.append(i)
        
        res = []
        for i in nums1:
            if i in m:
                res.append(m[i])
            else:
                res.append(-1)
        return res