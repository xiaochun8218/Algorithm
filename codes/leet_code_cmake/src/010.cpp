#include "subject.h"

bool Solution::isMatch(string s, string p)
{
    //动态规划

    //1.定义状态
        //dp[i][j] 表示s的前i个字符，可以被p的前j个字符匹配
    //2.状态转移
        //a) if s[i-1] == p[j-1]                 ==> dp[i][j] = dp[i-1][j-1]
        //b) else if p[j-1] == '.'               ==> dp[i][j] = dp[i-1][j-1]
        //c) else if p[j-1] == '*'
        //  1.p[j-2] != s[i-1] && p[j-2] != '.'  ==> dp[i][j] = dp[i][j - 2]  //a* as empty

        //  2.else                               ==> dp[i][j] = dp[i][j-2]  //a* as empty
                                               //==> dp[i][j] = dp[i][j-1]  //a* as single a
                                               //==> dp[i][j] = dp[i-1][j]  //a* as multiple a
                
    //3.考虑边界
        //j -2 >= 0
    //4.考虑初值
        //dp[0][0] = true
        //dp[0][j]
        //dp[j][0]
    //5.考虑输出

    int n1 = s.size();
    int n2 = p.size();
    bool dp[n1 + 1][n2 + 1];
    memset(dp, false, (n1 + 1) * (n2 + 1));
    dp[0][0] = true;
    for (int j = 2; j <= n2; j++)
        dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
            {//第一个字符不会是'*',所以p[j-2]不会越界
                if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                {
                    dp[i][j] = dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[n1][n2];
}
