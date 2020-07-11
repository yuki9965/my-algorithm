#include<vector>
#include<iostream>
using namespace std;

/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>res;
        int l = 1, r = 2;
        int sum = l + r;
        while(l < r){
            if(sum == target){
                vector<int> tmp;
                for(int i = l; i <= r; ++i){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                sum -= l;
                l++;
            }
            else if(sum < target){
                r++;
                sum += r;
            }
            else{
                sum -= l;
                l++;
            }
        }
        return res;
    }
};