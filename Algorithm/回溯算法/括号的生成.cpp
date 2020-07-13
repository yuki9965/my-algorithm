#include<iostream>
#include<vector>
#include<string>
using namespace std;

//input : 括号的对数 n
//输出： 合法的括号

void backtrack(int left, int right, string& track, vector<string>& res) {
    // 可用的左括号数量为 left 个，可用的右括号数量为 rgiht 个
    //从左到右看，左括号的个数总是大于等于又括号的个数，
    //所以合法的括号应该有left <= right
    if(right < left)
        return;
    //< 0 就该结束了
    if(left < 0 || right < 0)
        return;
    //左右括号都用光了就加入结果
    if(left == 0 && right == 0)
    {
        res.push_back(track);
        return;
    }

    //做选择
    track.push_back('(');
    backtrack(left - 1, right, track, res);
    track.pop_back();

    track.push_back(')');
    backtrack(left, right - 1, track, res);
    track.pop_back();
}

vector<string> generateParenthesis(int n) {
    if(n == 0)
        return {};
    vector<string> res;
    string track;
    //初始左右括号都有 n 个
    backtrack(n, n, track, res);
    return res;
}



int  main(){
    int n;
    cin >> n;
    vector<string> res = generateParenthesis(n);
    for(string i : res)
        cout << i << endl;
    return 0;
}