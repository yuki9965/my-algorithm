class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int N = sizeof(int) * 8;
        const int K = 3;
        unsigned int res = 0;
        for (int i = 0; i < N; ++i) {
            int count = 0;
            for (auto num : nums) {
                count += ((unsigned int)num & (1 << i)) > 0;
            }
            if (count % K != 0) {
                res |= 1 << i;
            }
        }
        return (int)res;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int one = 0, two = 0, three;
//         for(auto num : nums)
//         {
//             two = two | (one&num);  //one&num意思是若one相应位和num相应位都为1，则该位出现了两次
//             one = one ^ num;  //记录出现一次的二进制位
//             three = two & one; //如果某一个为one 和 two都为1，说明他出现了三次
//             two &= ~three; //先对出现三次的位取反，变成0，再与，清除该位
//             one &= ~three;
//         }
//         return one; //返回只出现一次的数
//     }
// };