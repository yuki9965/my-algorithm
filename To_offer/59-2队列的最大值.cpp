#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，
要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1
*/

/*
类似滑动窗口，入队是r++，出队是l++
*/

class MaxQueue {
public:
    queue<int> q;
    deque<int> maxq;
    MaxQueue() {

    }
    
    int max_value() {
        return q.empty() ? -1 : maxq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!maxq.empty() && value > maxq.back())
            maxq.pop_back();
        maxq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int res = q.front();
        q.pop();
        if(res == maxq.front())
            maxq.pop_front();
        return res;
    }
};

