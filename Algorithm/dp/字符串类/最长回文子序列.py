class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        m = len(s)
        dp = [[0 for i in range(m)] for j in range(m)]

        # dp[i][j] : s[i~j]的最长回文子序列长度
        # base case,对角线上总为1
        for i in range(m):
            dp[i][i] = 1

        # 目标是dp[0][m-1] 要反着遍历
        for i in range(m-2, -1, -1):
            for j in range(i+1, m):
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    # 子序列与子串不同，
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        
        return dp[0][m-1]