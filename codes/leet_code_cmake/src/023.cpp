#include "subject.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
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

ListNode* divideMerge(vector<ListNode*>& lists, int left, int right)
{
    //递归出口
    if (left == right)
        return lists[left];
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    ListNode* l1 = divideMerge(lists, left, mid);
    ListNode* l2 = divideMerge(lists, mid + 1, right);

    return mergeTwoLists(l1, l2);
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
    if (lists.empty())
        return nullptr;

    /*
    //1.遍历合
    ListNode* new_list = lists[0];
    ListNode* r = new_list;
    for (size_t i = 1; i < lists.size(); i++)
    {
        new_list = mergeTwoLists(new_list, lists[i]);
    }

    return new_list;
    */

    //2.二分合
    return divideMerge(lists, 0, lists.size() - 1);
}