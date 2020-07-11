#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
//任意一个丑数都是由小于它的某一个丑数*2，*3或者*5得到的
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        if(index == 1)
            return 1;
        vector<int> dp(index);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0; //设置三个队列头
        for(int i=1; i<index; ++i){
            dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
            if(dp[p2]*2 == dp[i]) p2++;
            if(dp[p3]*3 == dp[i]) p3++;
            if(dp[p5]*5 == dp[i]) p5++;
        }
        return dp[index - 1];
    }
};