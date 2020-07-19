#include<vector>
#include<math.h>
using namespace std;


/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，
打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素
代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
*/

/*
f(n,s)=f(n-1,s-1)+f(n-1,s-2)+f(n-1,s-3)+f(n-1,s-4)+f(n-1,s-5)+f(n-1,s-6)
f(n, s) 表示n个骰子点数的和为s的排列情况总数
第n个骰子点数为1的话，f(n,s)=f(n-1,s-1),以此类推
*/
vector<double> twoSum(int n) {
    vector<vector<int>>dp(n+1, vector<int>(6*n+1, 0)); 
    vector<double> ans (5*n+1, 0); //
    double all=pow(6,n);
    //n = 1时，f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1
    for(int i=1;i<=6;i++)
        dp[1][i]=1;
        
    for(int i=1;i<=n;i++){
        for(int j=i;j<=6*n;j++){
            for(int k=1;k<=6;k++){
                dp[i][j] += j >= k ? dp[i-1][j-k] : 0;
                //我们要求的是n个骰子的情况
                if(i==n)
                    ans[j-i]=dp[i][j]/all;
            }
        }
    }
    return ans;
}

int main(){
    vector<double> res = twoSum(1);
    return 0;
}