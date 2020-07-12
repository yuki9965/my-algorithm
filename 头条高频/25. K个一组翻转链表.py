/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == nullptr or head->next == nullptr or k < 2)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        for(ListNode *prev = &dummy, *end = head; end; end = prev->next)
        {
            for(int i = 1; i<k && end; i++)
                end = end->next;
            if(end == nullptr)
                break;
            prev = reverse(prev, prev->next, end);
        }
        return dummy.next;
    }
    
    ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end)
    {
        ListNode *end_next = end->next;
        ListNode *p = begin, *cur = p->next, *next = cur->next;
        while(cur != end_next)
        {
            cur->next = p;
            p = cur;
            cur = next;
            next = next ? next->next : nullptr; 
        }
        prev->next = p;
        begin->next = end_next;
        return begin;
    }
};