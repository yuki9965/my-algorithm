#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *pHead1, ListNode *pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        
        int len1 = 0, len2 = 0;
        for(ListNode* p=pHead1; p!=nullptr; p=p->next){
            len1++;
        }
        for(ListNode* p=pHead2; p!=nullptr; p=p->next){
            len2++;
        }
        
        //找到长的那个
        int lendif = len1 - len2;
        ListNode* longhead = pHead1;
        ListNode* shorthead = pHead2;
        
        if(len2 > len1){
            lendif = len2 - len1;
            longhead = pHead2;
            shorthead = pHead1;
        }
        
        //让长的先走
        while(lendif--){
            longhead = longhead->next;
        }
        //然后一起走
        while(longhead != nullptr && shorthead != nullptr){
            if(longhead == shorthead)
                break;
            longhead = longhead->next;
            shorthead = shorthead->next;
        }
        
        ListNode* res = longhead;
        return res;        
    }
};