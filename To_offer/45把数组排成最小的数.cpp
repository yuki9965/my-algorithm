#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string minNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), compare);
        string res = "";
        for(vector<int>::size_type i=0; i<numbers.size(); ++i){
            res += to_string(numbers[i]);
        }
        return res;
    }
    
    //"3" > "321"
    static bool compare(int a, int b){
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        return A < B;
    }
};