/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> ret;
        if (head == NULL)
          return ret;
        ListNode* p = head;
        stack<int> list;
        while(p != NULL)
        {
            list.push(p->val);
            p = p->next;
        }
        while(!list.empty())
        {
            ret.push_back(list.top());
            list.pop();
        }
        return ret;
    }
};