class Solution():

    def isMatch(s, p):

        def dp(i, j, s, p):
            if memo.has_key((i, j)):
                return memo[(i, j)]
            if i == len(s):
                return j == len(p)

            first = i < len(s) and (p[j] == s[i] or p[j] == '.')

            if j <= len(p) - 2 and p[j + 1] == '*':
                ans = dp(i, j + 2, s, p) or (first and dp(i + 1, j, s, p))
            
            else:
                ans = first and dp(i + 1, j + 1, s, p)
            
            memo[(i, j)] = ans
            
            return ans
        
        memo = {}
        return dp(0,0,s,p)