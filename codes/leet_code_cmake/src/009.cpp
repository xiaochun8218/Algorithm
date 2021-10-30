#include "subject.h"

bool Solution::isPalindrome(int x)
{
    //1.��ÿ��λ�����ֱ�������
    //2.����ָ�룬����һ��
    if (x < 0)
        return false;

    vector<int> v_data;
    while (x > 0)
    {
        v_data.emplace_back(x % 10);
        x /= 10;
    }

    int i = 0, j = v_data.size() - 1;
    while (i <= j)
    {
        if (v_data[i] != v_data[j])
            return false;
        i++;
        j--;
    }
    return true;
}