# 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

# candidates 中的每个数字在每个组合中只能使用一次。

# 说明：

# 所有数字（包括目标数）都是正整数。
# 解集不能包含重复的组合。 
# 示例 1:

# 输入: candidates = [10,1,2,7,6,1,5], target = 8,
# 所求解集为:
# [
#   [1, 7],
#   [1, 2, 5],
#   [2, 6],
#   [1, 1, 6]
# ]
# 示例 2:

# 输入: candidates = [2,5,2,1,2], target = 5,
# 所求解集为:
# [
#   [1,2,2],
#   [5]
# ]



class Solution:
    
    def combinationSum2(self, candidates, target):
        res = []
        if len(candidates) == 0:
            return res

        def backtrack(lo, hi, candidates, target, track):
            if sum(track) == target:
                res.append(track[:])
                return
            for i in range(lo, hi + 1):
                if sum(track) + candidates[i] > target:
                    break

                if i > lo and candidates[i - 1] == candidates[i]:
                    continue
                
                track.append(candidates[i])
                backtrack(i+1, hi, candidates, target, track)
                track.pop()

        candidates.sort()
        track = []
        backtrack(0, len(candidates)-1, candidates, target, track)
        return res
    

# class Solution:

#     def combinationSum2(self, candidates, target):
#         def dfs(begin, path, residue):
#             if residue == 0:
#                 res.append(path[:])
#                 return

#             for index in range(begin, size):
#                 # 剪枝
#                 if candidates[index] > residue:
#                     break
#                 # 去重        
#                 if index > begin and candidates[index - 1] == candidates[index]:
#                     continue
#                 path.append(candidates[index])
#                 dfs(index + 1, path, residue - candidates[index])
#                 path.pop()

#         size = len(candidates)
#         if size == 0:
#             return []

#         # sort去重
#         candidates.sort()
#         res = []
#         dfs(0, [], target)
#         return res



if __name__ == "__main__":
    so = Solution()
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    print(so.combinationSum2(candidates, target))