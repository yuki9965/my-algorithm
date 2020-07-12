# class Solution {
# public:
#     vector<int> plusOne(vector<int>& digits) {
#         int c = 1; 
#         // 从最后开始
#         for(auto i=digits.rbegin(); i!=digits.rend(); i++)
#         {
#             *i += c;
#             c = *i / 10; //进位
#             *i %= 10;
#         }
#         if(c > 0)
#             digits.insert(digits.begin(), 1);
#         return digits;
#     }
# };

def plusone(digits):
    c = 1
    for i in range(len(digits)-1, -1, -1):
        digits[i] += c
        c = digits[i] // 10
        digits[i] = digits[i] % 10
    if c > 0:
        digits.insert(c, 0)
    return digits

if __name__ == "__main__":
    digits = [7,8,9]
    print(plusone(digits))
