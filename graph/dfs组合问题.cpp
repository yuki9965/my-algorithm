#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 100; //题目允许的最大的N
int n;
int x[N]; //标记

void dfs(int depth){
    if(depth >= n){
        bool printendl = false;
        for (int i = 0; i < n; ++i){
            if(x[i] != 0){
                cout << i + 1;
                printendl = true;
            }
        }
        if(printendl)
            cout << endl;
        return;
    }
    //dfs，要或不要
    x[depth] = 0;
    dfs(depth + 1);
    x[depth] = 1;
    dfs(depth + 1);
}

int main(){
    cin >> n;
    dfs(0);
    return 0;
}