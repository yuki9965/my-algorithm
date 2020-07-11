#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        return mergesort(nums, 0, nums.size()-1);
    }

    int mergesort(vector<int>& nums, int lo, int hi){
        if(lo >= hi)
            return 0;
        int mid = lo + (hi-lo)/2;
        int left = mergesort(nums, lo, mid);
        int right = mergesort(nums, mid+1, hi);
        return left + right + mergecount(nums, lo, mid, hi);
    }

    int mergecount(vector<int>& nums, int lo, int mid, int hi){
        int i = lo, j = mid + 1;
        int aux[nums.size()];
        int count = 0;

        for(int k=lo; k<=hi; ++k){
            aux[k] = nums[k];
        }

        for(int k=lo; k<=hi; ++k){
            if(i > mid)
                nums[k] = aux[j++];
            else if(j > hi)
                nums[k] = aux[i++];
            else if(aux[i] > aux[j]){ //此时逆序了
                nums[k] = aux[j++];
                count += mid - i + 1;
            }
            else
                nums[k] = aux[i++];
        }
        return count;
    }
};