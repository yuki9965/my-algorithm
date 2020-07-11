#include<bits/stdc++.h>
using namespace std;

/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。
在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。
*/

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
            return n;
        n -= 9;
        long long count = 90, dig = 2;
        //计算数位
        while (n > count * dig)
        {
            n -= (count * dig);
            count *= 10;
            dig++;
        }
        //寻找对应的那个数字
        long long num = pow(10, dig - 1) + n / dig;
        //如果刚好这个数字是在最后一位那就是上一个数字的最后一位 例如n 11 计算出来按道理是11，其实对应的是10的0
        if (n % dig == 0)
        {
            num--;
            return num % 10;
        }
        else
        { //如果是这个数的第二位例如 7888 那么应该78/100%10
            for (int i = 0; i < (dig - n % dig); i++)
            {
                num /= 10;
            }
            return num % 10;
        }
    }
};