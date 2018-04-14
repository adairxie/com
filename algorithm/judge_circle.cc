/** 
* Definition for singly-linked list. 
*/
struct ListNode { 
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
}; 

class Solution {
public:
    ListNode * detectCycle(ListNode * head) {        
        if (NULL == head) return NULL;
        ListNode * fast = head;
        ListNode * slow = head; 
        
        while (1)
        {
            fast = fast->next ? fast->next : NULL;            
            if (NULL == fast) break;

            fast = fast->next ? fast->next : NULL;            
            if (NULL == fast) break;
            
            slow = slow->next;    
            if (slow == fast) break;
        }        
        if (NULL == fast)  return NULL;
        
        ListNode * cur = head;
        ListNode * inter = slow;        
        while (cur != inter)
        {
            cur = cur->next;
            inter = inter->next;
        }        
        return cur;
    }
};
