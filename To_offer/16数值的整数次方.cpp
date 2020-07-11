#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i=abs(n); i>0; i = i/2){
            if(i % 2 != 0)
            {
                res *= x;
            }
            x *= x;
        }
        if(n < 0)
            return 1.0 / res;
        return res;
    }
};