#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
//摩尔投票法 N
//或者排序 NlgN
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int times = 0, result = 0;
        for(auto num : numbers){
            if(times == 0){
                result = num;
                times = 1;
            }
            else if(result == num)
                times++;
            else
                times--;
        }
        times = 0;
        for(int num : numbers){
            if(result == num)
                times++;
        }
        return times > numbers.size()/2 ? result : 0;
    }
};