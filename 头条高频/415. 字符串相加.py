class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        sb = ""
        c = 0
        i = len(num1)-1
        j = len(num2)-1
        while i >= 0 or j >= 0 or c != 0:
            if i >= 0:
                c += int(num1[i])
                i -= 1
            if j >= 0:
                c += int(num2[j])
                j -= 1
            sb += str(c % 10)
            c = c // 10
        return sb[::-1]