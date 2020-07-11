#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
示例
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
*/

/*
单调双向队列，队头存的是最大值（的标号），往队尾依次减小
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    if(nums.size() == 0)
        return {};
    deque<int> q;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i){
        //当新的元素比尾部的元素大，就把尾部的pop
        while(!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();
        //往队尾添加
        q.push_back(i);
        //当窗口已经滑出去了
        if(!q.empty() && i - q.front() > k - 1)
            q.pop_front();
        if(i >= k-1){
            res.push_back(nums[q.front()]);
        }
    }
    return res;
}

