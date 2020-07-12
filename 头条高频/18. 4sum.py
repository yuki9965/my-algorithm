class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) 
            return res;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for(auto i=nums.begin();i<last-3;i++)
        {
            if (i>nums.begin() && *i == *(i-1))
                continue;
            for(auto j=i+1;j<last-2;j++)
            {
                if(j>i+1 && *j == *(j-1))
                    continue;
                
                auto k = j + 1;
                auto l = last - 1;
                while(k<l)
                {
                    if(*i + *j + *k + *l < target)
                    {
                        k++;
                        while(*k==*(k-1) && k<l)
                            k++;
                    }
                    else if(*i + *j + *k + *l > target)
                    {
                        l--;
                        while(*l == *(l+1) && k<l)
                            l--;
                    }
                    else
                    {
                        res.push_back({*i, *j, *k, *l});
                        k++;
                        l--;
                        while(*k == *(k-1) && *l == *(l+1) && k<l)
                            k++;
                    }
                }
            }
        }
        return res;
        
    }
};