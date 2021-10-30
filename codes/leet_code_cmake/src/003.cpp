#include "subject.h"

int Solution::lengthOfLongestSubstring(string s)
{
    if (s.empty())
        return 0;
    //�������ڷ�
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int res = 0;

    //��������
    while (right < s.size())
    {
        char ch = s.at(right);
        right++;

        //�������ݸ���
        window[ch]++;

        //���ڼ�С
        while (window[ch] > 1)
        {
            char del = s.at(left);
            left++;

            //�������ݸ���
            window[del]--;
        }

        //����������
        if ((right - left) > res)
            res = right - left;
    }

    return res;
}