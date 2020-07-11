#include<vector>
#include<iostream>
using namespace std;

/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
示例 1
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
*/

class Solution {
public:
/*
nums = [1,2,10,4,1,4,3,3]
a^a=0
a^0=a
a^b^c=a^c^b
a&(-a)=最低位为1的二进制（从又到左）
所有的异或结果得到sum=2^10=8
flag=-8&8=8
可分为两组，一组为与flag相与等于1的[10]，另一组为0的[1,2,4,1,4,3,3]
组内异或分别得到【10】【2】
*/
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum ^= num;     //找到不同的那两个数的异或
        }
        //因为两个数不同，所以必有一位为1
        //找到最低位的那个为1的二进制数，两个数在这一位上的01不同
        int flag = (-sum) & sum;    

        vector<int> res(2, 0);
        //按这个位，把数组分成两个部分
        for(int num :  nums){
            if((flag&num) == 0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};



