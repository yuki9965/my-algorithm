/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。
请找出那个只出现一次的数字。
输入：nums = [9,1,7,9,7,9,7]
输出：1
*/

#include<vector>
#include<iostream>
using namespace std;

int singleNumber(vector<int>& nums){
    int res = 0;
    for (int i = 0; i < 32; ++i){
        int bit = 1 << i; //当前要操作的位
        int cnt = 0;
        for(int num : nums){
            if((bit&num) != 0)  
                cnt++;
        }
        //如果数字出现了3次，那么当前这个位的位数可以被3整除
        //如果不行，说明res在这个位是1
        if(cnt % 3 != 0)
            res |= bit;
    }
    return res;
}