#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for(int num : pushed){
            s.push(num);
            while(!s.empty() && s.top() == popped[j] && j < popped.size()){
                s.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};

