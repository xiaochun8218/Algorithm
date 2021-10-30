#include "subject.h"

int Solution::lengthOfLongestSubstring(string s)
{
    if (s.empty())
        return 0;
    //滑动窗口法
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int res = 0;

    //窗口增大
    while (right < s.size())
    {
        char ch = s.at(right);
        right++;

        //窗口数据更新
        window[ch]++;

        //窗口减小
        while (window[ch] > 1)
        {
            char del = s.at(left);
            left++;

            //窗口数据更新
            window[del]--;
        }

        //输出结果更新
        if ((right - left) > res)
            res = right - left;
    }

    return res;
}