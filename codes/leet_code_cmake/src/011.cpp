#include "subject.h"

int Solution::maxArea(vector<int>& height)
{
    //左右双指针
    //面积 (right - left)*min(y_left, y_right)
    //左右指针移动，因为移动后，right - left 一定是减小的，所以谁矮谁移动

    if (height.empty())
        return 0;

    int res = 0;
    int left = 0, right = height.size() - 1;
    while (left < right)
    {
        //计算面积
        int area = (right - left) * min(height[left], height[right]);
        res = max(res, area);

        //移动指针
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return res;
}