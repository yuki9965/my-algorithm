class Solution:
    def strToInt(self, str: str) -> int:
        str = str.strip()
        if not str:
            return 0
        res, start, sign = 0, 1, 1
        int_min, int_max, boundary = -2**31, 2**31 - 1, (2**31-1) // 10
        if str[0] == '-':
            sign = -1
        elif str[0] != '+': # 说明此时没有显式的符号位，调整start
            start = 0
        for char in str[start:]:
            if char < '0' or char > '9':
                break
            if res > boundary or res == boundary and char > '7':
                return int_min if sign == -1 else int_max
            else:
                res = res * 10 + ord(char) - ord('0')
        
        return res * sign