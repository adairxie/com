#include <stdio.h>
#include <malloc.h>

struct ListNode_s {
    int val;
    struct ListNode_s *next;
};

typedef struct ListNode_s ListNode_t;

ListNode_t* FindKthToTail(ListNode_t* pListHead, unsigned int k)
{
    if (pListHead == NULL || k < 1)
        return NULL;

    ListNode_t *pAhead = pListHead;
    ListNode_t *pBehind = pListHead;

    int i;
    for(i = 0; i < k-1; i++)
    {
        if (pAhead->next == NULL)
            break;
        pAhead = pAhead->next;
    }

    if (i != k-1 )
        return NULL;

    while (pAhead->next != NULL) {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}

int main(int argc, char** argv)
{
    ListNode_t *pHead, *p;
    int i;
    for (i = 0; i < 10; i++)
    {
        if (pHead == NULL)
        {
            pHead = (ListNode_t*)malloc(sizeof(ListNode_t));
            pHead->val = i;
            p = pHead;
            continue;
        }
        
        p->next = (ListNode_t*)malloc(sizeof(ListNode_t));
        p->next->val = i;
        p = p->next;
    }

    
    /*
    while(pHead != NULL) {
        p = pHead->next;
        free(pHead);
        pHead = p;
    }*/

    while(1) {
        ListNode_t *res = FindKthToTail(pHead, 3);
        printf("result is %d\n", res->val);
    }
}
