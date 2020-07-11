#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

//dp[i]代表长度为i的绳子所构成乘积的最大值。

class Solution {
public:
    int cuttingRope(int n) {
        int *dp = new int[n+1];
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * (i - j));
            }
        }
        return dp[n];
    }
};