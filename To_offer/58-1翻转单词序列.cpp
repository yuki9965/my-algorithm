#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
则输出"student. a am I"。
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
*/
string reverseWords(string s) {
    if(s.size() == 0)
        return s;
    string res = "";
    reverse(s.begin(), s.end());
    auto lo = 0, hi = 0;
    for(; lo < s.size(); hi++){
        while(s[lo] == ' ' && lo < s.size()){
            lo++;
        }
        if(s[lo] != ' ' && (s[hi] == ' ' || s[hi] == '\0') && hi > lo){
            string tmp = s.substr(lo, hi - lo);
            reverse(tmp.begin(), tmp.end());
            res += tmp;
            if(s[hi] == ' ')
                res += ' ';
            lo = hi + 1;
        }
    }
    if(res.size() > 0 && res[res.size()-1] == ' ')
        res.erase(res.size()-1);
    return res;
}

// 双指针法 python
// class Solution:
//     def reverseWords(self, s: str) -> str:
//         s = s.strip() # 删除首尾空格
//         i = j = len(s) - 1
//         res = []
//         while i >= 0:
//             while i >= 0 and s[i] != ' ': i -= 1 # 搜索首个空格
//             res.append(s[i + 1: j + 1]) # 添加单词
//             while s[i] == ' ': i -= 1 # 跳过单词间空格
//             j = i # j 指向下个单词的尾字符
//         return ' '.join(res) # 拼接并返回

// 一行法
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.strip().split()[::-1])


