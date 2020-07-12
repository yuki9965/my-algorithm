class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res {};
        if(nums.size() == 0)    return res;
        sort(nums.begin(), nums.end());
        vector<int>::iterator i = nums.begin(), last = nums.end();
        int target = 0;

        for(; i<last-2; ++i){
            if(i > nums.begin() && *i == *(i-1))    continue;
            vector<int>::iterator j = i+1, k = last - 1;
            while(j < k){
                if(*i + *j + *k == target){
                    res.push_back({*i, *j, *k});
                    j++;
                    k--;
                    while(j<k && *j == *(j-1) && *k == *(k+1)){
                        k--;
                    }
                }
                else if(*i + *j + *k < target){
                    j++;
                    while(j < k && *j == *(j-1))
                        j++;
                }

                else{
                    k--;
                    while(j < k && *k == *(k+1))
                        k--;
                }
            }
        }
        return res;
    }
};


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        return self.nSum(nums, 3, 0, 0)

    def nSum(self, nums, n, start, target):
        size = len(nums)
        res = []

        if n < 2 or n > size:
            return res
        
        if n == 2:
            lo, hi = start, size - 1
            while lo < hi:
                s = nums[lo] + nums[hi]
                left, right = nums[lo], nums[hi]
                if s < target:
                    while lo < hi and nums[lo] == left: lo += 1
                elif s > target:
                    while lo < hi and nums[hi] == right: hi -= 1
                else:
                    res.append([left, right])
                    while lo < hi and nums[lo] == left: lo += 1
                    while lo < hi and nums[hi] == right: hi -= 1
        else:
            # 当n > 2, 递归计算(n-1)sum 结果
            for i in range(start, size):
                sub = self.nSum(nums, n-1, i+1, target-nums[i])
                for arr in sub:
                    arr.append(nums[i])
                    res.append(arr)
                while i < size-1 and nums[i] == nums[i+1]:  i +=1
        
        return res