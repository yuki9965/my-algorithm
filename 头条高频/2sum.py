class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num = nums[:]
        nums = sorted(nums)
        res = []
        lo, hi = 0, len(nums)-1

        while lo < hi:
            left, right = nums[lo], nums[hi]
            s = left + right

            if s < target:
                while lo < hi and nums[lo] == left:
                    lo += 1
            if s > target:
                while lo < hi and nums[hi] == right:
                    hi -= 1
            else:
                res = [left, right]
                while lo < hi and nums[lo] == left:
                    lo += 1
                while lo < hi and nums[hi] == right:
                    hi -= 1
        # 
        return res 