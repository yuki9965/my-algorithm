#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
dfs与回溯的区别：
1.回溯是一种更通用的算法。可以用于任何类型的结构，其中可以消除域的部分 ——无论它是否是逻辑树。
2.深度优先搜索是与搜索树或图结构相关的特定回溯形式。它使用回溯作为其使用树的方法的一部分，但仅限于树/图结构。
3.回溯和 DFS 之间的区别在于回溯处理隐式树而 DFS 处理显式树。这似乎微不足道，但它意味着很多。
当通过回溯访问问题的搜索空间时，隐式树在其中间被遍历和修剪。然而对于 DFS 来说，它处理的树/图是明确构造的，
并且在完成任何搜索之前已经抛出了不可接受的情况，即修剪掉了。
4.因此，回溯是隐式树的 DFS，而 DFS 是回溯而不修剪。
*/

const int N = 13; //最大值
vector<int> track;  //记录当前解
vector<vector<int>> res; //记录所有解
int visited[N] = {0}; //是否被遍历过
int n;

void dfs(vector<int>& track){
    if(track.size() >= n){
        res.push_back(track);
        return;
    }
    for (int i = 1; i <= n; ++i){
        if(visited[i] == 0){
            visited[i] = 1;
            track.push_back(i);
            dfs(track);
            visited[i] = 0;
            track.pop_back();
        }
    }
}

int main(){
    cin >> n;
    vector<int> track;
    dfs(track);
    for(auto i : res){
        for(auto j : i){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}