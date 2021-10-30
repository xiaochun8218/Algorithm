#pragma once

#include <iostream>

class SeniorSort
{
public:
    SeniorSort();
    ~SeniorSort();

    //汉诺塔
    void move(int n, char x, char z);

    void hannoi(int n, char x, char y, char z);

    //N皇后
    int nCount = 0;
    bool check(int row, int col, int solution[]);

    void backtracking(int n, int row, int solution[]);

    int totalCount(int n);


    //二分查找
    int binarySearch(int arr[], const int key, int low, int high);
};
