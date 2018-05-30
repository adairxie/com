#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode_s     BinaryTreeNode_t;
typedef struct LinkQueue_s      LinkQueue_t;

struct BinaryTreeNode_s
{
    int                 m_nValue;
    BinaryTreeNode_t*   m_pLeft;
    BinaryTreeNode_t*   m_pRight;
};

struct LinkQueue_s  {
    BinaryTreeNode_t *node;
    LinkQueue_t *next; 
};

LinkQueue_t*
InitLinkQueue(BinaryTreeNode_t* node)
{
    LinkQueue_t *queue = (LinkQueue_t*)malloc(sizeof(LinkQueue_t));
    queue->node = node;
    queue->next = NULL;

    return queue;
}

void
EnLinkQueue(LinkQueue_t** q, BinaryTreeNode_t* node)
{
    if (q == NULL || node == NULL) {
        return;
    }

    if (*q == NULL) {
        *q = InitLinkQueue(node);
        return;
    }

    LinkQueue_t *tail = *q;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = InitLinkQueue(node);
}

LinkQueue_t*
DeLinkQueue(LinkQueue_t** queue)
{
    if (queue == NULL || *queue == NULL) {
        return NULL;
    }

    if ((*queue)->next == NULL) {
        return *queue;
    }

    LinkQueue_t **head = queue;
    queue = &((*queue)->next);
    (*head)->next = NULL;
    return *head;
}

BinaryTreeNode_t*
ConstructCore(int* startPreorder, int* endPreorder,
              int* startInorder, int* endInorder)
{
    BinaryTreeNode_t* root = (BinaryTreeNode_t*)malloc(sizeof(BinaryTreeNode_t));
    int rootValue = startPreorder[0];
    root->m_nValue = rootValue;
    root->m_pLeft = NULL;
    root->m_pRight = NULL;

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            return NULL;
        }
    }

    int* rootInorder = startInorder;
    int preOrderLength = 0;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        rootInorder++;
        preOrderLength++;
    }

    if (startInorder < rootInorder) {
        root->m_pLeft = ConstructCore(startPreorder+1, startPreorder+preOrderLength,
                                      startInorder, rootInorder-1);
    }

    if (rootInorder < endInorder) {
        root->m_pRight = ConstructCore(startPreorder+1+preOrderLength,
                                       endPreorder, rootInorder+1, endInorder);
    }
    return root; 
}

BinaryTreeNode_t*
Construct(int* preorder, int* inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    return ConstructCore(preorder, preorder+length-1, 
        inorder, inorder+length-1);
}


void test()
{
    BinaryTreeNode_t node;
    node.m_nValue = 1;
    LinkQueue_t *q = InitLinkQueue(&node);
    printf("%d\n", q->node->m_nValue);

    BinaryTreeNode_t node2;
    node2.m_nValue = 2;
    BinaryTreeNode_t node3;
    node3.m_nValue = 3;

    
    EnLinkQueue(&q, &node2);
    EnLinkQueue(&q, &node3);

    LinkQueue_t

    //LinkQueue_t *out = DeLinkQueue(&q);
    //printf("%d\n", out->node->m_nValue);
}

int main(int argc, char** argv)
{
    int preOrder[] = {7, 4, 1, 6, 5, 13, 8, 10};
    int inOrder[] = {1, 4, 5, 6, 7, 8, 13, 10};

    test();
    
    BinaryTreeNode_t* root = Construct(preOrder, inOrder, 8);
    printf("root:%d\n", root->m_nValue);
}
