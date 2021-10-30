#include "subject.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    if (!head)
        return nullptr;

    //1.˫ָ��
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

    //2.ɾ�����
    if (pre)
    {
        pre->next = q->next;
    }
    else
    {//Ҫɾ�����ǵ�һ�����
        return head->next;
    }
    
    return head;
}