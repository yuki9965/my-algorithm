#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

*/

/*
因为题目中给的元素是 < len（nums）的，所以我们可以让 位置i 的地方放元素i。
如果位置i的元素不是i的话，那么我们就把i元素的位置放到它应该在的位置，
即 nums[i] 和nums[nums[i]]的元素交换，这样就把原来在nums[i]的元素正确归位了。
如果发现 要把 nums[i]正确归位的时候，发现nums[i]（这个nums[i]是下标）
那个位置上的元素和要归位的元素已经一样了，说明就重复了，重复了就return。
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

