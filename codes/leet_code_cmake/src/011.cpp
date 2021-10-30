#include "subject.h"

int Solution::maxArea(vector<int>& height)
{
    //����˫ָ��
    //��� (right - left)*min(y_left, y_right)
    //����ָ���ƶ�����Ϊ�ƶ���right - left һ���Ǽ�С�ģ�����˭��˭�ƶ�

    if (height.empty())
        return 0;

    int res = 0;
    int left = 0, right = height.size() - 1;
    while (left < right)
    {
        //�������
        int area = (right - left) * min(height[left], height[right]);
        res = max(res, area);

        //�ƶ�ָ��
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return res;
}