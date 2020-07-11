
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        //创建复制节点N'，并链接到 N 的后面
        RandomListNode* pCur = pHead;
        while(pCur != nullptr){
            RandomListNode* pCloned = new RandomListNode(pCur->label); //创建副本
            pCloned->next = pCur->next;
            pCur->next = pCloned;
            pCur = pCloned->next;
        }
        
        //按照原来的给N'复制random指针
        pCur = pHead;
        while(pCur != nullptr){
            RandomListNode* pCloned = pCur->next;
            if(pCur->random != nullptr)
                pCloned->random = pCur->random->next;
            pCur = pCloned->next;
        }
        
        //分裂
        pCur = pHead;
        RandomListNode dummy(-1);
        RandomListNode* pCloned = &dummy;
        while(pCur != nullptr){
            pCloned->next = pCur->next;
            pCloned = pCloned->next;
            pCur->next = pCloned->next;
            pCur = pCur->next;
        }
        return dummy.next;
    }
    
    
    //O(n)空间 + O(n)时间
    /**
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, RandomListNode*> m;
    
        for(RandomListNode* p = pHead; p; p = p->next){
            m[p] = new RandomListNode(p->label);
        }
        for(RandomListNode* p = pHead; p; p = p->next){
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
        }
        return m[pHead];
    }
    **/
};