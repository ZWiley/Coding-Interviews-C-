/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
     /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *curNode = pHead;
        while(curNode){
            RandomListNode *node = new RandomListNode(curNode->label);
            node->next = curNode->next;
            curNode->next = node;
            curNode = node->next;
        }
        curNode = pHead;
        while(curNode){
            RandomListNode *node = curNode->next;
            if(curNode->random){
                node->random = curNode->random->next;
            }
            curNode = node->next;
        }
        //
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        curNode = pHead;
        while(curNode->next){
            tmp = curNode->next;
            curNode->next = tmp->next;
            curNode = tmp;
        }
        return pCloneHead;
    }
};