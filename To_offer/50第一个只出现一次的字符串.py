# python 3.6之后的字典是有序的
# 考察HaspMap的使用
class Solution:
    def firstUniqChar(self, s: str) -> str:
        map = dict()
        for char in s:
            map[char] = not char in map
        for k, v in map.items():
            if v:
                return k
        return ' '

            