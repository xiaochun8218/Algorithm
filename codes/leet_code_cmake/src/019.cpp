#include "subject.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    if (!head)
        return nullptr;

    //1.双指针
    ListNode* p = head;
    ListNode* q = head;
    ListNode* pre = nullptr;
    for (size_t i = 0; i < n; i++)
    {
        if (p)
            p = p->next;
    }

    while (p)
    {
        p = p->next;
        pre = q;
        q = q->next;
    }

    //2.删除结点
    if (pre)
    {
        pre->next = q->next;
    }
    else
    {//要删除的是第一个结点
        return head->next;
    }
    
    return head;
}