#include "subject.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    //1.遍历
    //2.注意进位

    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* p_ret = new ListNode(0, nullptr);;
    ListNode* p3 = p_ret;
    int carry = 0;
    while (p1 || p2)
    {
        int num_1 = p1 ? p1->val : 0;
        int num_2 = p2 ? p2->val : 0;
        int sum = num_1 + num_2 + carry;
        carry = sum / 10;
        ListNode* new_node = new ListNode(sum % 10, nullptr);

        p3->next = new_node;
        p3 = p3->next;

        if (p1)
            p1 = p1->next;
        if (p2)
            p2 = p2->next;
    }
    if (carry > 0)
    {
        ListNode* new_node = new ListNode(carry, nullptr);
        p3->next = new_node;
    }

    return p_ret->next;
}