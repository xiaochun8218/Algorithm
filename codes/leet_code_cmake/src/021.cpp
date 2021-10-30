#include "subject.h"

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* l3 = nullptr;
    if (p->val > q->val)
    {
        l3 = q;
        q = q->next;
    }
    else
    {
        l3 = p;
        p = p->next;
    }
    ListNode* r = l3;

    while (p && q)
    {
        if (p->val > q->val)
        {
            r->next = q;
            q = q->next;
        }
        else
        {
            r->next = p;
            p = p->next;
        }
        r = r->next;
    }

    if (p)
        r->next = p;
    if (q)
        r->next = q;

    return l3;
}