
def lengthOfLongestSubstring(s: str) -> int:
    # 滑动窗口
    temp = set()
    left, right = 0, 0
    maxlen = 0
    while right < len(s):
        c1 = s[right]
        right += 1
        while c1 in temp:
            temp.remove(s[left])
            left += 1
        temp.add(c1)
        if right - left > maxlen:
            maxlen =  right - left
    
    return maxlen

if __name__ == "__main__":
    s = "pwwkew"
    res = lengthOfLongestSubstring(s)
    pass