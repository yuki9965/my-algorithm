#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums;
        auto odd = nums.begin();
        auto even = nums.end()-1;
        while(odd < even){
            if(*odd % 2 == 1)
                odd++;
            else{
                swap(*odd, *even);
                even--;
            }
        }
        return nums;
    }
};