#pragma once

#include "linklist/linklist.h"
#include <iostream>
#include <vector>

class SortBase
{
public:
    SortBase();
    ~SortBase();

    //��������
    void insertSort(int arr[], int len);

    //ϣ������
    void shellSort(int arr[], int len);

    //ѡ������
    void selectSort(int arr[], int len);

    //������
    void adjustHeap(int arr[], int len, int nodePos);

    void heapSort(int arr[], int len);

    //ð������
    void bubbleSort(int arr[], int len);

    //��������
    int partition(int arr[], int left, int right);

    void quickSort(int arr[], int left, int right);


    //��·-�鲢����
    void merge(int arr[], int low, int mid, int high);

    void mergePass(int arr[], int len, int length);

    void mergeSort(int arr[], int len);

    //��������
    void countSort(int arr[], int len);

    //Ͱ����
    void insertNode(Node* head, int val);

    Node* mergeList(Node* headOne, Node* headTwo);

    void bucketSort(int arr[], int len);

    //��������radixSort
    int getMaxElem(int arr[], int len);

    void countSortByExp(int arr[], int len, int exp);

    void radixSort(int arr[], int len);
};
