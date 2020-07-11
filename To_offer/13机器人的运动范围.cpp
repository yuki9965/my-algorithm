#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格
（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 1：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20
*/

//回溯，判断条件
int movingCount(int m, int n, int k) {
    if(k < 0 || m <= 0 || n <= 0)
        return 0;
    bool *visited = new bool[m * n]; //标记数组
    memset(visited, 0, m * n);
    int count = backtrack(k, m, n, 0, 0, visited);
    delete[] visited;
    return count;
}

int backtrack(int k, int rows, int cols, int row, int col, bool *visited){
    int count = 0;
    if(row >= 0 && row < rows && col >= 0 && col < cols && 
        !visited[row*cols + col] && check(k, row, col)){
        visited[row * cols + col] = 1;
        count = 1 + backtrack(k, rows, cols, row + 1, col, visited) 
                + backtrack(k, rows, cols, row - 1, col, visited) 
                + backtrack(k, rows, cols, row, col - 1, visited) 
                + backtrack(k, rows, cols, row, col + 1, visited);
    }
    return count;
}

bool check(int k, int row, int col){
    int sum = 0;
    while(row > 0 || col > 0){
        sum = sum + row % 10 + col % 10;
        row = row / 10;
        col = col / 10;
    }
    return sum <= k ? true : false;
}