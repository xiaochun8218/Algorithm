#pragma once

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node()
        :data(0)
        , next(nullptr)
    {
    }
    Node(int val)
        :data(val)
        , next(nullptr)
    {
    }
};

class LinkList
{
public:
    LinkList();
    ~LinkList();

    //逆序构造单链表
    void descCreatLinkList(Node* header);

    //链表反转
    void reverseLinkList(Node* header);

    //链表快排
    Node* partion(Node* begin, Node* end);

    void quickSortLinkList(Node* begin, Node* end);

    //合并两个有序链表
    Node* mergeLinkList(Node* head1, Node* head2);

    //返回链表的倒数第K个节点的值
    int lastKNum(Node* head, int k);

    //链表删除某个值的节点
    void delNodeVal(Node* head, int val);

    //链表删除指定节点pos, 要求平均时间复杂度为 O(1)
    //虽然pos是最后一个节点时，时间复杂度为O(n),但pos是其他n-1个节点时，复杂度均为O(1)
    //合起来的平均复杂度为：( (n-1)O(1) + O(n) ) / n, 仍然为O(1).
    //LC_237
    void deleteNode(Node* head, Node* node);

    //找到链表中的中间节点 LC_876
    Node* middleNode(Node* head);

    //判断链表是否有环,如果有环，返回相遇节点
    Node* isHaveLoop(Node* head);

    //在一个有环的链表中找到环的入口节点
    //1.找到环中某一节点
    //2.计算出环长度n
    //3.两个指针找到环入口节点
    Node* detectCycle(Node* head);
};
