//交换律：a ^ b ^ c <=> a ^ c ^ b
//任何数于0异或为任何数 0 ^ n => n
//相同的数异或为0: n ^ n => 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto i : nums)
        {
            x = x ^ i;
        }
        return x;
    }
};