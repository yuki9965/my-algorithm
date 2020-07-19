
# 找到两边第一个比他高的值
# 和 84 最大矩形正好相反
class Solution:
    def trap(self, height: list) -> int:
        length = len(height)
        if length < 3:
            return 0
        # 定义一个单调减的单调栈，存的是下标
        # 一旦遇到一个比top高的数，因为左边也是比top高的，就可以存水了
        #  然后计算当前这个top的位置可以存多少水 
        # width 就是 右边的边界 i 减 当前栈顶的元素
        # height 就是 看左右边界哪个更低。木桶原理，按照最低的高度计算
        res = 0
        stack = []
        for i in range(length):
            while stack and height[stack[-1]] < height[i]:
                top = stack.pop()
                # 如果此时为空，说明左边没有高的边界，不能存水
                if not stack:
                    break
                curWidth = i - stack[-1] - 1
                curHeight = min(height[i], height[stack[-1]]) - height[top]

                res += curHeight * curWidth
            stack.append(i)
        return res