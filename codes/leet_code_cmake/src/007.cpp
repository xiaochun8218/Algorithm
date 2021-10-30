#include "subject.h"

int Solution::reverse(int x)
{
    //1.不用单独处理符号
    //2.反向输出  
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