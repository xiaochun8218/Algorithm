#include "subject.h"

string Solution::longestPalindrome(string s)
{
    //��̬�滮��
    //1.����״̬
    //dp[i][j] :�±�i-->j���Ӵ��Ƿ�Ϊ�����Ӵ�

    //2.״̬ת��
        //s[i] != s[j] һ�����ǻ��Ĵ�
        //(s[i] == s[j]) && dp[i+1][j-1] ����β�����ַ���ͬ��ȥ����β�����ַ���Ȼ�ǻ��Ĵ�

    //3.���Ǳ߽磺����[i+1, j-1]ֻ��һ��Ԫ��
    //(j-1) - (i+1) + 1 < 2 ==> j - i < 3 ==> j - i + 1 < 4

    //4.���ǳ�ʼ��
    //���ַ��Ӵ���dp[i][i] = 1

    //5.�������
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