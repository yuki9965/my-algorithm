# 单调栈
# 关键在于找到每个元素 heights[i]的左右边界，即左边第一个比他小的，和右边第一个比他小的
# 

def findToRight(heights):
    right = [None for i in range(len(heights))]
    stack = []

    for i in range(len(heights)):
        while stack and heights[stack[-1]] > heights[i]:
            right[stack.pop()] = i - 1
        stack.append(i)
    
    while stack:
        index = stack.pop()
        right[index] = len(heights) - 1
    
    return right

def findToLeft(heights):
    left = [None for i in range(len(heights))]
    stack = []

    for i in range(len(heights)-1, -1, -1):
        while stack and heights[stack[-1]] > heights[i]:
            left[stack.pop()] = i + 1
        stack.append(i)
    
    while stack:
        index = stack.pop()
        left[index] = 0
    
    return left

def largestRectangleArea(heights):
    right = findToRight(heights)
    left = findToLeft(heights)

    res = 0
    for i in range(len(heights)):
        res = max(res, (right[i] - left[i] + 1) * heights[i])
    
    return res

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights = [0] + heights + [0]
        stack = []
        res = 0
        for i in range(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                tmp = stack.pop()
                res = max(res, (i - stack[-1] - 1) * heights[tmp])
            stack.append(i)
        return res

if __name__ == "__main__":
    heights = [2,1,5,6,2,3]
    res = largestRectangleArea(heights)
    print(res) 
    pass

