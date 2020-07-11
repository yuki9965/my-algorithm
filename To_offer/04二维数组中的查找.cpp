#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m <= 0)
            return false;
        int n = matrix[0].size();
        //从右上角开始,可以看成一个二叉搜索树
        int x = 0, y = n - 1;
        while(y >= 0 && x < m){
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target)
                y--;
            else
                x++;
        }
        return false;
    }
};