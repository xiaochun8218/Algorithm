#pragma once

#include "linklist/linklist.h"
#include <iostream>
#include <vector>

class SortBase
{
public:
    SortBase();
    ~SortBase();

    //²åÈëÅÅĞò
    void insertSort(int arr[], int len);

    //Ï£¶ûÅÅĞò
    void shellSort(int arr[], int len);

    //Ñ¡ÔñÅÅĞò
    void selectSort(int arr[], int len);

    //¶ÑÅÅĞò
    void adjustHeap(int arr[], int len, int nodePos);

    void heapSort(int arr[], int len);

    //Ã°ÅİÅÅĞò
    void bubbleSort(int arr[], int len);

    //¿ìËÙÅÅĞò
    int partition(int arr[], int left, int right);

    void quickSort(int arr[], int left, int right);


    //¶şÂ·-¹é²¢ÅÅĞò
    void merge(int arr[], int low, int mid, int high);

    void mergePass(int arr[], int len, int length);

    void mergeSort(int arr[], int len);

    //¼ÆÊıÅÅĞò
    void countSort(int arr[], int len);

    //Í°ÅÅĞò
    void insertNode(Node* head, int val);

    Node* mergeList(Node* headOne, Node* headTwo);

    void bucketSort(int arr[], int len);

    //»ùÊıÅÅĞòradixSort
    int getMaxElem(int arr[], int len);

    void countSortByExp(int arr[], int len, int exp);

    void radixSort(int arr[], int len);
};
