#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"及
"-1E-16"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
*/

class Solution {
public:
    //判断底数是否合法
    bool judgeP(string s){
        bool res = false, point = false;
        for (int i = 0; i < s.size(); ++i){
            if(s[i] == '+' || s[i] == '-'){ //符号只能出现在第一位
                if(i != 0)
                    return false;
            }

            else if(s[i] == '.'){    //. 只能出现一次
                if(point == true)
                    return false;
                point = true;
            }
            else if(s[i] < '0' || s[i] > '9')
                return false;
            else
                res = true;
        }
        return res;
    }

    //判断指数是否合法
    bool judgeS(string s){
        bool res = false;

        for (int i = 0; i < s.size(); ++i){
            if(s[i] == '+' || s[i] == '-'){ //符号只能出现在第一位
                if(i != 0)
                    return false;
            }
            //指数不能出现小数点
            else if(s[i] < '0' || s[i] > '9')
                return false;
            else
                res = true;
        }
        return res;
    }

    bool isNumber(string s) {
        int i = s.find_first_not_of(' ');
        if(i == string::npos)
            return false;
        int j = s.find_last_not_of(' ');
        s = s.substr(i, j - i + 1);
        if(s.empty())
            return false;

        int e = s.find('e');
        int E = s.find('E');
        
        if(e == string::npos && E == string::npos)
            return judgeP(s);
        else if(e != string::npos)
            return judgeP(s.substr(0, e)) && judgeS(s.substr(e + 1));
        else
            return judgeP(s.substr(0, E)) && judgeS(s.substr(E + 1));
    }

};
