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
    ListNode* getKthFromEnd(ListNode* pListHead, int k) {
        if(k<=0 || pListHead == nullptr)
            return nullptr;
        ListNode* p1 = pListHead;
        ListNode* p2 = pListHead;
        for(; k>1; k--){
            if(p2->next != nullptr)
                p2 = p2->next;
            else
                return nullptr;
        }
        while(p2->next != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};