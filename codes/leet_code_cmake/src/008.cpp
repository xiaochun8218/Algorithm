#include "subject.h"

int Solution::myAtoi(string s)
{
    /*函数 myAtoi(string s) 的算法如下：

        读入字符串并丢弃无用的前导空格
        检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
        读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
        将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
        如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
        返回整数作为最终结果。
        注意：

        本题中的空白字符只包括空格字符 ' ' 。
        除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。*/

    int n = s.size();
    if (0 == n)
        return 0;

    int64_t res = 0;
    bool has_find_num = false;
    int flag_num = 0;
    int flag = 1;
    for (int pos = 0; pos < n; pos++)
    {
        char ch = s.at(pos);

        //去空格
        if (ch == ' ' && has_find_num == false && flag_num == 0)
            continue;

        //符号
        if (has_find_num == false)
        {
            if (ch == '-')
            {
                if (flag_num == 0)
                {//第一个符号
                    flag_num++;
                    flag = -1;
                    continue;
                }
                else
                    break;
            }
            if (ch == '+')
            {
                if (flag_num == 0)
                {//第一个符号
                    flag_num++;
                    continue;
                }
                else
                    break;
            }
        }     
        
        //定位到第一个数
        if (res == 0 && !(ch >= '0' && ch <= '9'))
            break;

        //数后面遇到字符，结束
        if (res > 0 && !(ch >= '0' && ch <= '9'))
            break;

        res = res * 10 + (ch - '0');
        has_find_num = true;

        if (res > INT32_MAX)
            break;
        else if (res < INT32_MIN)
            break;
    }

    res *= flag;
    if (res > INT32_MAX)
        res = INT32_MAX;
    else if (res < INT32_MIN)
        res = INT32_MIN;

    return res;
}