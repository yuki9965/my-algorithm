class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k == 0:
            return []
        deque = collections.deque()
        # 未形成窗口
        for i in range(k):
            while deque and deque[-1] < nums[i]:
                deque.pop()
            deque.append(nums[i])
        res = [deque[0]]
        # 已经形成窗口
        for i in range(k, len(nums)):
            while deque and deque[-1] < nums[i]:
                deque.pop()
            deque.append(nums[i])
            if deque[0] == nums[i-k]:
                deque.popleft()
            res.append(deque[0])
        return res
        