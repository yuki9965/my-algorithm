class Solution:
    def longestPalindrome(self, s: str) -> str:
        m = len(s)
        # dp[i][j]= 0/1 表示[i~j]是否是回文
        dp = [[0 for i in range(m)] for j in range(m)]
        start = 0  # 起始index
        maxlen = 1  # 最大长度

        # base case,对角线上总为1
        for i in range(m):
            dp[i][i] = 1

        # base 初始化长度为2
        for i in range(0, m-1):
            dp[i][i+1] = 1 if s[i] == s[i+1] else 0
            if dp[i][i+1] == 1:
                start = i
                maxlen = 2
        
        # 反着遍历
        for i in range(m-3, -1, -1):
            for j in range(i+2, m):
                if s[i] == s[j] and dp[i+1][j-1]:
                    dp[i][j] = 1
                    if j - i + 1 > maxlen:
                        start = i
                        maxlen = j - i + 1
                else:
                    dp[i][j] = 0

        return s[start:start+maxlen]