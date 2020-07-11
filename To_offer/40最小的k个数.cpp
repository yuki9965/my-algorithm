#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//1.快排
//2.大顶堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& input, int k) {
        priority_queue<int, vector<int>, less<int> > leastNumbers; //大顶堆
        if(k < 1 || input.size() < k)
            return vector<int> {};
        
        auto iter = input.begin();
        for(; iter < input.end(); ++iter){
            if(leastNumbers.size() < k)
                leastNumbers.push(*iter);
            else{
                //auto iterGreast = leastNumbers.begin(); //第一个元素是最大的
                if(*iter < leastNumbers.top()){
                    leastNumbers.pop();
                    leastNumbers.push(*iter);
                }
            }
        }
        vector<int> res;
        while(!leastNumbers.empty()){
            res.insert(res.begin(), leastNumbers.top());
            leastNumbers.pop();
        }
        return res;
    }
};

//3.计数排序
class Solution {
    public:
     vector<int> getLeastNumbers(vector<int> arr, int k) {
        if (k == 0 || arr.size() == 0) {
            return new int[0];
        }
        // 统计每个数字出现的次数
        int *counter = new int[10001];
        for (int num: arr) {
            counter[num]++;
        }
        // 根据counter数组从头找出k个数作为返回结果
        int *res = new int[k];
        int idx = 0;
        for (int num = 0; num < counter.length; num++) {
            while (counter[num]-- > 0 && idx < k) {
                res[idx++] = num;
            }
            if (idx == k) {
                break;
            }
        }
        return res;
    }
}