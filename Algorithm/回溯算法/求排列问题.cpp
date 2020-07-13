#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> res;

void backtrack(vector<int> &track, int N)
{
    if (track.size() == N)
    {
        res.push_back(track);
    }

    for (int i = 1; i <= N; ++i)
    {
        if(find(track.begin(), track.end(), i) != track.end())
            continue;
        track.push_back(i);
        backtrack(track, N);
        track.pop_back();
    }
}
