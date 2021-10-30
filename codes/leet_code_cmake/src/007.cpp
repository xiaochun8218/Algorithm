#include "subject.h"

int Solution::reverse(int x)
{
    //1.���õ����������
    //2.�������  
    int64_t res = 0;
    while (x != 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    if (res > INT32_MAX || res < INT32_MIN)
        res = 0;
    
    return res; 
}