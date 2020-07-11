#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    stack<int> m_data;
    stack<int> m_min;
    void push(int value) {
        m_data.push(value);
        //压入栈顶元素和当前元素的最小值
        if(m_min.empty() || value < m_min.top())
            m_min.push(value); 
        //新来的value不是最小值，在min栈中重复放入当前的最小值，始终与data大小相同
        else
            m_min.push(m_min.top());
    }
    void pop() {
        //assert(!m_data.empty() && !m_min.empty());
        m_data.pop();
        m_min.pop();
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
};

