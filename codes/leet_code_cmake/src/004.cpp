#include "subject.h"

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    //1.合并成一个正序数组
    //2.寻找中位数

    double d_ret = 0.0;
    if (nums1.empty() && nums2.empty())
        return d_ret;

    vector<int> nums3;
    auto iter_1 = nums1.begin();
    auto iter_2 = nums2.begin();
    while (iter_1 != nums1.end() && iter_2 != nums2.end())
    {
        if (*iter_1 < *iter_2)
        {
            nums3.emplace_back(*iter_1);
            iter_1++;
        }
        else
        {
            nums3.emplace_back(*iter_2);
            iter_2++;
        }
    }

    while (iter_1 != nums1.end())
    {
        nums3.emplace_back(*iter_1);
        iter_1++;
    }
    while (iter_2 != nums2.end())
    {
        nums3.emplace_back(*iter_2);
        iter_2++;
    }

    //寻找中位数
    int n = nums3.size();
    if (n % 2 == 0)
    {//偶数
        int pos = n / 2;
        d_ret = (nums3[pos - 1] + nums3[pos]) / 2.0;
    }
    else
    {//奇数
        int pos = ceil(n / 2.0);
        d_ret = nums3[pos - 1];
    }

    return d_ret;
}