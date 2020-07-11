#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

//二分查找，剔除重复
class Solution {
public:
    int minArray(vector<int>& rotateArray) {
        int len = rotateArray.size();
        if( len == 0)
            return 0;
        int lo = 0, hi = len - 1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(rotateArray[mid] > rotateArray[hi])
                lo = mid+1;
            else if(rotateArray[mid] < rotateArray[hi])
                hi = mid;
            else
                hi--;
        }
        return rotateArray[lo];
    }
};