class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1; 
        for(auto i=digits.rbegin(); i!=digits.rend(); i++)
        {
            *i += c;
            c = *i / 10; //进位
            *i %= 10;
        }
        if(c > 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};