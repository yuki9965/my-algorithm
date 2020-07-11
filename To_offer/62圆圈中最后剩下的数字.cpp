#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};

int LastRemaining_Solution(int n, int m)
{
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    //构造环链表
    for (int i = 1; i < n; ++i){
        head->next = new ListNode(i);
        head = head->next;
    }
    head->next = dummy; //连上环
    head = dummy;

    while(n > 1){
        //找到前驱节点
        ListNode *prev = head;
        if(m == 1){
            for (int i = 1; i < n; ++i){
                prev = prev->next;
            }
        }
        else
            for (int i = 1; i < m - 1; ++i){
                prev = prev->next;
            }

        ListNode *deletenode = prev->next; //要删除的节点
        prev->next = deletenode->next;
        delete deletenode;
        head = prev->next;
        n--;
    }
    return head->val;
}

//数学方法
int lastRemaining(int n, int m){
    int ans = 0;
    for (int i = 2; i <= n; ++i){
        ans = (ans + m) % i;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << lastRemaining(n, m);
    return 0;
}