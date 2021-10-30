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

    //�����쵥����
    void descCreatLinkList(Node* header);

    //����ת
    void reverseLinkList(Node* header);

    //�������
    Node* partion(Node* begin, Node* end);

    void quickSortLinkList(Node* begin, Node* end);

    //�ϲ�������������
    Node* mergeLinkList(Node* head1, Node* head2);

    //��������ĵ�����K���ڵ��ֵ
    int lastKNum(Node* head, int k);

    //����ɾ��ĳ��ֵ�Ľڵ�
    void delNodeVal(Node* head, int val);

    //����ɾ��ָ���ڵ�pos, Ҫ��ƽ��ʱ�临�Ӷ�Ϊ O(1)
    //��Ȼpos�����һ���ڵ�ʱ��ʱ�临�Ӷ�ΪO(n),��pos������n-1���ڵ�ʱ�����ӶȾ�ΪO(1)
    //��������ƽ�����Ӷ�Ϊ��( (n-1)O(1) + O(n) ) / n, ��ȻΪO(1).
    //LC_237
    void deleteNode(Node* head, Node* node);

    //�ҵ������е��м�ڵ� LC_876
    Node* middleNode(Node* head);

    //�ж������Ƿ��л�,����л������������ڵ�
    Node* isHaveLoop(Node* head);

    //��һ���л����������ҵ�������ڽڵ�
    //1.�ҵ�����ĳһ�ڵ�
    //2.�����������n
    //3.����ָ���ҵ�����ڽڵ�
    Node* detectCycle(Node* head);
};
