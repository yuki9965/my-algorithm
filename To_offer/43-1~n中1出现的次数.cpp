#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        string numstr = to_string(n);
        int first = numstr[0] - '0';
        int numpow = int(pow(10, numstr.size() - 1)); //1234 => 1000
        int last = n - first * numpow; //234

        if(first == 1){
            // 最高位是1，如1234, 此时pow = 1000,那么结果由以下三部分构成：
            // (1) dfs(pow - 1)代表[0,999]中1的个数;
            // (2) dfs(last)代表234中1出现的个数;
            // (3) last+1代表first固定为1有多少种情况。
            return countDigitOne(numpow - 1) + countDigitOne(last) + last + 1;

        }
        else{
            // 最高位不为1，如2234，那么结果也分成以下三部分构成：
            // (1) pow代表固定高位1，有多少种情况;
            // (2) first * dfs(pow - 1)代表999以内和1999以内低三位1出现的个数;
            // (3) dfs(last)同上。
            return numpow + first * countDigitOne(numpow - 1) + countDigitOne(last);
        }

    }
};