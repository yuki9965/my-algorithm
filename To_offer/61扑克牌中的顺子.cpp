#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//排序方法 NlgN
//看看0的个数够不够填补
bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int zero = 0;
    for (int i = 0; i < nums.size(); ++i){
        if(nums[i] == 0)
            zero++;
        else if(i < nums.size() && nums[i+1] == nums[i])
            return false;
        else{ 
            if(i < nums.size())
                zero -= nums[i + 1] - nums[i] - 1;
        }
    }
    return zero >= 0;
}

//不排序方法
//如果 maxValue - minValue + 1 > 5maxValue−minValue+1>5，
//说明题目给的 5 张牌不足以构成顺子，返回 falsefalse .
//如果 maxValue - minValue + 1 <= 5maxValue−minValue+1<=5，说明 5 张牌足以构成顺子
//注意跳过0和判断有无重复的牌
bool isStraight(vector<int>& nums) {
    bool v[15] = {0}; //0-13
    int minnum = 14, maxnum = 0;
    for(int num : nums){
        if(num == 0)
            continue;
        if(v[num] == 1)
            return false;
        v[num] = 1;
        minnum = min(minnum, num);
        maxnum = max(maxnum, num);
    }
    return maxnum - minnum + 1 <= 5;
}