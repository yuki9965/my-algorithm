#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
vector<int> res;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return res;
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int i=0;
        while(i<=m-i && i<=n-i){
            printOneTime(i,m-i, n-i, matrix);
            i++;
        }
        return res;
    }

    void printOneTime(int p1, int m, int n, vector<vector<int> > matrix){
    //从左到右打印一行
    for(int i=p1; i<=n; ++i)
        res.push_back(matrix[p1][i]);
    //从上到下打印一列
    if(p1 < m){
        for(int i=p1+1; i<=m; ++i)
            res.push_back(matrix[i][n]);
    }
    //从右到左
    //至少有两行两列
    if(p1 < m && p1 < n){
        for(int i=n-1; i>=p1; --i)
            res.push_back(matrix[m][i]);
    }
    //从下到上
    //至少有三行两列
    if( p1 < n && p1 < m-1){
        for(int i=m-1; i>=p1+1; --i)
            res.push_back(matrix[i][p1]);
    }
    }
};
111