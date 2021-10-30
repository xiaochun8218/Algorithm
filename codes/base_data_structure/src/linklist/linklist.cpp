#include "linklist/linklist.h"

using namespace std;

LinkList::LinkList()
{

}

LinkList::~LinkList()
{

}

void LinkList::descCreatLinkList(Node* header)
{
    Node* pre = nullptr;
    int x = 0;
    while (cin >> x && x != -1)
    {
        Node* cur = new Node;
        cur->data = x;
        cur->next = pre;
        pre = cur;
    }
    header->next = pre;
}

void LinkList::reverseLinkList(Node* header)
{
    if (header->next == nullptr || header->next->next == nullptr)
    {
        return;
    }

    Node* pre = nullptr;
    Node* cur = header->next;
    while (cur)
    {
        Node* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    header->next = pre;
}

Node* LinkList::partion(Node* begin, Node* end)
{
    int key = begin->data;
    Node* i = begin;
    Node* j = begin->next;

    while (j != end)
    {
        if (j->data < key)
        {
            // (i,j)区间的节点的data都是大于key的
            i = i->next;            // i要先往后移一位，保证换到右边的是比key大的值
            swap(i->data, j->data); // 换完之后，i的值是比key小的
        }
        j = j->next;
    }
    swap(i->data, begin->data); // 确定了key的位置i

    return i;
}

void LinkList::quickSortLinkList(Node* begin, Node* end)
{
    if (begin == end || begin->next == end)
    {
        return;
    }

    Node* i = partion(begin, end);
    quickSortLinkList(begin, i);
    quickSortLinkList(i->next, end);
}

Node* LinkList::mergeLinkList(Node* head1, Node* head2)
{
    Node* headNew = new Node(0);
    Node* r = headNew;

    Node* p = head1->next;
    Node* q = head2->next;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }

    if (p)
        r->next = p;
    if (q)
        r->next = q;

    return headNew;
}

int LinkList::lastKNum(Node* head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return -1;
    }
    Node* p = head->next;
    Node* q = head->next;
    for (int i = 0; i < k; i++)
    {
        if (!p)
        {
            cout << "linklist length less then k" << endl;
            return -1;
        }
        p = p->next;
    }

    while (p)
    {
        p = p->next;
        q = q->next;
    }

    return q->data;
}

void LinkList::delNodeVal(Node* head, int val)
{
    if (head == nullptr || head->next == nullptr)
        return;

    /*
    Node * pre = head;
    Node * p = head->next;
    while (p)
    {
        if (p->data != val)
        {
            pre = p;
            p = p->next;
        }
        else
        {
            pre->next = p->next;
            free(p);
        }
    }
    */
    Node* p = head->next;
    while (p)
    {
        if (p->data != val)
        {
            p = p->next;
        }
        else
        {
            Node* tmp = p->next;
            p->data = tmp->data;
            p->next = tmp->next;
            //free(tmp);
            break;
        }
    }
}

void LinkList::deleteNode(Node* head, Node* node)
{
    if (node == nullptr)
        return;

    if (node->next == nullptr)
    {
        Node* p = head;
        while (p->next != node)
            p = p->next;
        p->next = nullptr;
        //free(node);
    }
    else
    {
        Node* tmp = node->next;
        node->data = tmp->data;
        node->next = tmp->next;
        //free(tmp);
    }
}

Node* LinkList::middleNode(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* LinkList::isHaveLoop(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node* slow = head;
    Node* fast = head->next;
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* LinkList::detectCycle(Node* head)
{
    Node* meetNode = isHaveLoop(head);
    if (meetNode == nullptr)
        return nullptr;

    int n = 1;
    Node* p = meetNode->next;
    while (p != meetNode)
    {
        n++;
        p = p->next;
    }

    p = head;
    Node* q = head;
    for (int i = 0; i < n; i++)
    {
        if (!q)
            return nullptr;
        q = q->next;
    }

    while (p != q)
    {
        if (q == nullptr)
            return nullptr;
        p = p->next;
        q = q->next;
    }

    return p;
}
