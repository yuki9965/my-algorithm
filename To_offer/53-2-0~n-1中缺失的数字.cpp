#include<vector>
#include<iostream>
using namespace std;

/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。


示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    // 对于有序数组, 大小为i的数应当处于下标为i的位置上, 如果不在, 说明在该数字之前发生了错位
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] != mid) {
            right = mid - 1;
        }else { 
            left = mid + 1;
        }
    }
    // 如果从0 ~ n - 1都不缺值, 则缺少的是n
    return left;
    }
};