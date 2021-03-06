#include "sort/sort.h"
#include <iostream>
#include <vector>
using namespace std;

SortBase::SortBase()
{

}
SortBase::~SortBase()
{

}

void SortBase::insertSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SortBase::shellSort(int arr[], int len)
{
    int gap = len / 2;
    while (gap)
    {
        for (int i = gap; i < len; i++)
        {
            int key = arr[i];
            int j = i - gap;
            while ((j >= 0) && (arr[j] > key))
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
        gap /= 2;
    }
}

void SortBase::selectSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void SortBase::adjustHeap(int arr[], int len, int nodePos)
{
    int left = 2 * nodePos + 1;
    int right = 2 * nodePos + 2;

    int maxPos = nodePos;
    if ((left < len) && (arr[left] > arr[maxPos]))
    {
        maxPos = left;
    }
    if ((right < len) && (arr[right] > arr[maxPos]))
    {
        maxPos = right;
    }

    if (maxPos != nodePos)
    {
        int tmp = arr[nodePos];
        arr[nodePos] = arr[maxPos];
        arr[maxPos] = tmp;

        adjustHeap(arr, len, maxPos);
    }
}

void SortBase::heapSort(int arr[], int len)
{
    for (int i = (len - 1) / 2; i >= 0; i--)
    {
        adjustHeap(arr, len, i);
    }

    for (int i = len - 1; i >= 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        adjustHeap(arr, i, 0);
    }
}

void SortBase::bubbleSort(int arr[], int len)
{
    bool bHasChange = true;
    for (int i = 0; i < len - 1 && bHasChange; i++)
    {
        bHasChange = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bHasChange = true;
            }
        }
    }
}

int SortBase::partition(int arr[], int left, int right)
{
    int key = arr[left];

    int i = left;
    int j = right;
    while (i != j)
    {
        while ((i < j) && (arr[j] >= key))
            j--;
        arr[i] = arr[j];
        while ((i < j) && (arr[i] <= key))
            i++;
        arr[j] = arr[i];
    }
    arr[i] = key;

    return i;
}

void SortBase::quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int i = partition(arr, left, right);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

void SortBase::merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1;
    int k = 0;
    int* tmp;
    tmp = (int*)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        tmp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    for (k = 0, i = low; i <= high; k++, i++)
    {
        arr[i] = tmp[k];
    }

    free(tmp);
}

void SortBase::mergePass(int arr[], int len, int length)
{
    int i;
    for (i = 0; i + 2 * length - 1 < len; i = i + 2 * length)
    {
        //相邻的两个子序列，排序合并
        merge(arr, i, i + length - 1, i + 2 * length - 1);
    }

    if (i + length - 1 < len)
    {
        merge(arr, i, i + length - 1, len - 1);
    }
}

void SortBase::mergeSort(int arr[], int len)
{
    for (int length = 1; length < len; length = 2 * length)
    {
        mergePass(arr, len, length);
    }
}

void SortBase::countSort(int arr[], int len)
{
    int* countArr = (int*)malloc(100 * sizeof(int));
    int* sortArr = (int*)malloc(len * sizeof(int));

    for (int key = 0; key < 100; key++)
    {
        countArr[key] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        countArr[arr[i]]++;
    }

    //前后计数相加，得到下标，后面会取相应key的下标
    for (int key = 0; key < 100; key++)
    {
        countArr[key] += countArr[key - 1];
    }

    for (int i = len - 1; i >= 0; i--)
    {//倒着循环，保证算法是稳定的（相同的key，排序后相对位置不变）
        int key = arr[i];
        int pos = countArr[key] - 1;
        sortArr[pos] = key;
        countArr[key]--; //可能会有相同的key，所以取过一次下标之后，相应的下标值要减1
    }

    for (int i = 0; i < len; i++)
    {
        arr[i] = sortArr[i];
    }

    free(countArr);
    free(sortArr);
}

void SortBase::insertNode(Node* head, int val)
{
    Node* newNode = new Node(val);
    Node* pre = head;
    Node* cur = head->next;

    while (cur && (cur->data < val))
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = newNode;
    newNode->next = cur;
}

Node* SortBase::mergeList(Node* headOne, Node* headTwo)
{
    Node* tmp = new Node(0);
    Node* r = tmp;

    Node* p = headOne->next;
    Node* q = headTwo->next;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }

    if (p)
        r->next = p;
    if (q)
        r->next = q;

    return tmp;
}

void SortBase::bucketSort(int arr[], int len)
{
    int nBucketNum = 10;
    vector<Node*> vBucketNode;

    for (int i = 0; i < len; i++)
    {
        int pos = arr[i] % nBucketNum;
        Node* head = vBucketNode.at(pos);
        insertNode(head, arr[i]);
    }

    Node* head = vBucketNode.at(0);
    for (int i = 1; i < nBucketNum; i++)
    {
        Node* headIn = vBucketNode.at(i);
        head = mergeList(head, headIn);
    }

    for (int i = 0; i < len; i++)
    {
        arr[i] = head->next->data;
        head = head->next;
    }
}

int SortBase::getMaxElem(int arr[], int len)
{
    int maxElem = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > maxElem)
        {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

void SortBase::countSortByExp(int arr[], int len, int exp)
{
    int* countArr = (int*)malloc(10 * sizeof(int));
    int* sortArr = (int*)malloc(len * sizeof(int));

    for (int key = 0; key < 10; key++)
    {
        countArr[key] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        int key = arr[i] / exp % 10;
        countArr[key]++;
    }
    for (int key = 0; key < 10; key++)
    {
        countArr[key] += countArr[key - 1];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        int key = arr[i] / exp % 10;
        int pos = countArr[key] - 1;
        sortArr[pos] = arr[i];
        countArr[key]--;
    }

    for (int i = 0; i < len; i++)
    {
        arr[i] = sortArr[i];
    }

    free(countArr);
    free(sortArr);
}

void SortBase::radixSort(int arr[], int len)
{
    //获取最大的值
    int maxElem = getMaxElem(arr, len);
    //按位（个位、十位、百位...）进行计数排序
    for (int exp = 1; maxElem / exp > 0; exp = exp * 10)
    {
        countSortByExp(arr, len, exp);
    }
}
