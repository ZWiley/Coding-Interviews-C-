//输入一个链表，反转链表后，输出链表的所有元素。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        
        ListNode *pCurrent = pHead;
        ListNode *pReverseHead = NULL;
        ListNode *pPrev = NULL;

        while(pCurrent != NULL)
        {
            ListNode *pNext = pCurrent->next;

            if(pNext ==NULL)
                pReverseHead = pCurrent;
            
            pCurrent->next = pPrev;
            pPrev = pCurrent;
            pCurrent = pNext;
        }
        return pReverseHead;
    }
};