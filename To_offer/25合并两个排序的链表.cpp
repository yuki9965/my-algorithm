#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
        }
        if(p1 != nullptr)
            cur->next = p1;
        else if(p2 != nullptr)
            cur->next = p2;
        return dummy.next;
    }
};