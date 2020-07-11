#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> memo;

    bool isMatch(string s, string p) {
        return dp(0, 0, s, p);
    }
    
    bool dp(int i, int j, string s, string p){
        if(memo.count(make_pair(i,j)) != 0 )
            return memo[make_pair(i, j)];
        
        if(j == p.size())
            return i == s.size();

        bool firsr = i < s.size() && (p[j] == s[i] || p[j] == '.');

        bool ans;
        if(j <= p.size() - 2 && p[j+1] == '*'){
            //匹配该字符 0 次，然后跳过该字符和 * 或者 匹配一次,当p[0] 和 s[0] 匹配后，移动s
            ans = dp(i, j + 2, s, p) || (firsr && dp(i + 1, j, s, p));
        }
        else
        //否则都 + 1， 继续匹配下一个
            ans = firsr && dp(i + 1, j + 1, s, p);

        memo[make_pair(i, j)] = ans;
        return ans;
    }
};