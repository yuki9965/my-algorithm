class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i] 表示以nums[i]为结尾的最大子序和
        # 不能定义成[0-i]的最大子序和，这样不能归纳
        # 第i个要么加入前面的子序列，组成一个更大的子序和
        # 要么自成一派，单独作为一个子序列
        dp = [0] * len(nums)
        dp[0] = nums[0]
        res = dp[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i-1] + nums[i], nums[i])
            res = max(res, dp[i])
        
        return res