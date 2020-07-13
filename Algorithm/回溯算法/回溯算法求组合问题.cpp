/*
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        # 做选择
        将该选择从选择列表移除
        路径.add(选择)
        backtrack(路径, 选择列表)
        # 撤销选择
        路径.remove(选择)
        将该选择再加入选择列表
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if (k <= 0 || n <= 0) return res;
        vector<int> track;
        trackback(1, n, k, track);
        return res;
    }

    void trackback(int lo, int hi, int k, vector<int>& track){
        if(track.size() == k){
            res.push_back(track);
            return;
        }
        for(int i=lo; i<=hi; ++i){
            track.push_back(i); 
            trackback(i+1, hi, k, track);  
            //组合问题通过i+1来排除前面的重复
            //排列问题用 find 来排除重复
            track.pop_back();
        }
    }
};