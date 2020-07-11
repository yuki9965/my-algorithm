#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.size() == 0)
            return res;
            
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                //跳过已经标记的
                if(grid[i][j] == '0')
                    continue;
                //否则遍历所有与ij连通的 '1'
                res++;
                //dfs(grid, i, j);
                bfs(grid, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        //处理边界
        if(!(0 <=i && i < n && 0 <= j && j < m))
            return;
        //若已经被访问，直接跳过
        if(grid[i][j] == '0')   return;
        //已访问，打标记
        grid[i][j] = '0';
        //递归访问它所有邻居节点
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int> > q;
        int n = grid.size(), m = grid[0].size();
        q.push(make_pair(i,j));
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if(!(0 <=i && i < n && 0 <= j && j < m))
                continue;
            if(grid[i][j] == '0')
                continue;

            //先标记
            grid[i][j] = '0';
            
            q.push(make_pair(i+1,j));
            q.push(make_pair(i-1,j));
            q.push(make_pair(i,j+1));
            q.push(make_pair(i,j-1));
        }    
    }
};