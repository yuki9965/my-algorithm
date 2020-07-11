#include<bits/stdc++.h>
using namespace std;

/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> s1;
        int left = 0, right = 0;
        int maxlen = 0;

        while(right < s.size()){
            char c1 = s[right];
            right++;
            while(s1.count(c1) != 0){
                s1.erase(s[left]);
                left++;
            }
            s1.insert(c1);
            if(right - left > maxlen)
                maxlen = right - left;
        }
        return maxlen;
    }
};