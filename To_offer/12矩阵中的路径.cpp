#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，
每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) 
            return word.empty();
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (backtrack(board, row, col, word, 0)) return true;
            }
        }
        
        return false;
    }
private:
    bool backtrack(vector<vector<char>> &board, int row, int col, 
                   const string &word, int idx) {
        if (idx == word.size()) return true;
        if (row < 0 || row >= board.size() || 
            col < 0 || col >= board[0].size()) return false;
        if (word[idx] != board[row][col]) return false;
        
        board[row][col] = '*';
        if (backtrack(board, row - 1, col, word, idx + 1) || 
            backtrack(board, row + 1, col, word, idx + 1) ||
            backtrack(board, row, col - 1, word, idx + 1) || 
            backtrack(board, row, col + 1, word, idx + 1)) 
            return true;
        
        board[row][col] = word[idx];
        return false;
    }
};