#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    set<string> tmp;

    vector<string> permutation(string s) {
        if(s.size() == 0)
            return {};
        bool visited[s.size()];
        memset(visited, false, sizeof(visited));
        string track;
        trackback(track, s, visited);
        helper();
        return res;
    }

    void trackback(string& track, string& s, bool* visited){
        if(track.size() == s.size()){
            res.push_back(track);
            return;
        }
        for(int i = 0; i < s.size(); ++i){
            if(visited[i] == true)
                continue;
            track.push_back(s[i]);
            visited[i] = true;
            trackback(track, s, visited);
            track.pop_back();
            visited[i] = false;
        }
    }

    void helper(){
        for(string s : res){
            tmp.insert(s);
        }
        res.clear();
        for(string s : tmp)
            res.push_back(s);
        tmp.clear();
    }
};

