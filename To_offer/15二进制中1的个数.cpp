#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
         int res = 0;
        //一个整数减去1后与原来的整数按位与，可以将最右边的1变成0
         while(n){
             ++res;
             n = (n-1) & n;
         }
         return res;   
    }
};