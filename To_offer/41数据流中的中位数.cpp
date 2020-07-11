#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        //数量上时刻保持 小顶-大顶<=1（两堆相等或者小顶比大顶多一个）
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(max_heap.size() + 1 < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() > max_heap.size())
            return min_heap.top();
        else
            return double(max_heap.top() + min_heap.top()) / 2;
    }
};

