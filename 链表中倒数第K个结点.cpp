/**
输入一个链表，输出该链表中倒数第k个结点。
*/
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            if(pListHead == NULL || k == 0) 
                return NULL;
            ListNode *pTail = pListHead, *pHead = pListHead;
            for(int i = 1; i < k; ++i)
            {
                if(pHead->next != NULL)
                    pHead = pHead->next;
                else
                    return NULL;
            }
            while(pHead->next != NULL)
            {
                pHead = pHead->next;
                pTail = pTail->next;
            }
            return pTail;
    }
};