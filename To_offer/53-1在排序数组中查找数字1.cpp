#include<vector>
#include<iostream>
using namespace std;

/*
统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
*/
int left_bound(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1;
        }else{
            right = mid - 1;
        }
    }
    if(left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}

int right_bound(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    if(right < 0 || nums[right] != target)
        return -1;
    return right;
}

int search(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    int left = left_bound(nums, target);
    int right = right_bound(nums, target);
    cout << left << ',' << right << endl;

    if(left != -1 && right != -1)
        return right - left + 1;
    return 0;
}

int main(){
    vector<int> input = {5, 7, 7, 8, 8, 10};
    int t = 6;
    int res = search(input, t);
    cout << res;
    return 0;
}

