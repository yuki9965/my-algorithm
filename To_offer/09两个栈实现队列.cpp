#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>

using namespace std;

class CQueue {
public:
    stack<int>a;
    stack<int>b;

    CQueue() {}
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if(b.empty() && a.empty())
            return -1;
        if(b.empty() && !a.empty())
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        int tmp = b.top();
        b.pop();
        return tmp;  
    }
};