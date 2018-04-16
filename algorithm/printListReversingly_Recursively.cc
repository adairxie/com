#include <cstdio>

struct ListNode
{
    int     m_nKey;
    ListNode *next;
};

void PrintListRecursively(ListNode* pHead)
{
    if(pHead != NULL) {
        PrintListRecursively(pHead->next);
        printf("%d\n", pHead->m_nKey);
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pCur = new ListNode;
    pCur->m_nKey = value;
    pCur->next = NULL;

    if(*pHead == NULL) {
        *pHead = pCur;
    } else {
        ListNode *p = *pHead;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = pCur;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode* pToBeDeleted = NULL;
    if((*pHead)->m_nKey == value) {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;
    } else {
        ListNode *p = *pHead;
        while(p->next != NULL && p->next->m_nKey != value) {
            p = p->next;
        }

        ListNode *before = p;
        pToBeDeleted = p->next;
        if(pToBeDeleted != NULL && pToBeDeleted->next != NULL) {
            before->next = pToBeDeleted->next;
        } else {
            before->next = NULL;
        }
    }

    if(pToBeDeleted != NULL) {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

void test(void)
{
    ListNode *list = NULL;

    for(int i = 0; i < 10; i++) {
        AddToTail(&list, i);
    }

    PrintListRecursively(list);

    for(int i = 0; i < 10; i++) {
        RemoveNode(&list, i);
    }

    if(list == NULL) {
        printf("List is empty now!\n");
    }
}

int main(int argc, char** argv)
{
    test();
}
