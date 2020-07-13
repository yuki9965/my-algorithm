#题目：
# https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/submissions/ 剑指offer 11


# 寻找左边界
def left_bound(nums -> list, target -> int): -> int
    if len(nums) == 0:
        return - 1

    left, right = 0, len(nums) - 1

    while left <= right:                 # 停止索引条件是 left == right + 1
        mid = left + (right - left) // 2
        if nums[mid] == target:
            right = mid - 1             # 注意这里是 - 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    
    # 没有找到的情况
    if left >= len(nums) or nums[left] != target:
        return - 1

    return left

# 寻找右边界

def right_bound(nums -> list, target -> int): -> int
    if len(nums) == 0:
        return - 1
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1

    if right < 0 or nums[right] != target:
        return - 1

    return right
    

