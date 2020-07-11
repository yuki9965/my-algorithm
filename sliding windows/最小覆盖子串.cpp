#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/

string minWindow(string s, string t){
    int left = 0, right = 0;
    int start = 0, minLen = INT_MAX;

    unordered_map<char, int> window;
    unordered_map<char, int> needs;

    for(char c : t)
        needs[c]++;

    int match = 0; // 记录 window 中已经有多少字符符合要求了

    while(right < s.size()){
        char c1 = s[right];
        if(needs.count(c1)){
            window[c1]++;
            if(window[c1] == needs[c1])
                match++;
        }
        right++;
        while(match == needs.size()){ //这里是needs的size
            // 更新最小子串的位置和长度
            if(right - left < minLen){
                start = left;
                minLen = right - left;
            }
            //增加left，缩小窗口
            char c2 = s[left];
            if(needs.count(c2)){
                window[c2]--;
                if(window[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}