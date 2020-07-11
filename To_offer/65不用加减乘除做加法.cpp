#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
/*
 异或 ^ 相当于无进位的求和
 & 相当于求每位的进位数，即都是1的时候才进位，还要左移 << 一位
 所以公式就是(a^b) ^ ((a&b) << 1) 直到进位数为0未知 
*/
    int add(int a, int b) {
    
        while(b != 0){
            int tmp = a^b;
            b = ((unsigned int)(a&b) << 1); //c++不支持负值左移，需要强制转换为无符号数 
            a = tmp;
        }
        return a;
    }
};