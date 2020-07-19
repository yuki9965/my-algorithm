# 单调栈
# 关键在于找到每个元素 heights[i]的左右边界，即左边第一个比他小的，和右边第一个比他小的


# 找两边第一个小于他的值 与 42 相反
def largestRectangleArea(heights) -> int:
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

