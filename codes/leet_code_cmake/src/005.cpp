#include "subject.h"

string Solution::longestPalindrome(string s)
{
    //动态规划法
    //1.定义状态
    //dp[i][j] :下标i-->j的子串是否为回文子串

    //2.状态转移
        //s[i] != s[j] 一定不是回文串
        //(s[i] == s[j]) && dp[i+1][j-1] ：首尾两个字符相同，去掉首尾两个字符依然是回文串

    //3.考虑边界：区间[i+1, j-1]只有一个元素
    //(j-1) - (i+1) + 1 < 2 ==> j - i < 3 ==> j - i + 1 < 4

    //4.考虑初始化
    //单字符子串：dp[i][i] = 1

    //5.考虑输出
    //TODO

    int begin = 0;
    int max_len = 1;
    int n = s.size();
    int dp[n][n];
    for (size_t i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (s[i] != s[j])
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j - i < 3)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }

            if (dp[i][j] == 1)
            {
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
        }
    }

    return s.substr(begin, max_len);
}