#include "subject.h"

bool Solution::isValid(string s)
{
    if (s.empty())
        return true;

    //1.遇到左括号，入栈
    //2.遇到右括号，和栈顶元素匹配
    //  a.匹配上了，弹栈，继续匹配
    //  b.没匹配上，return false
    std::stack<char> st;
    for (size_t i = 0; i < s.size(); i++)
    {
        char ch = s.at(i);
        if (ch == '(' || ch == '[' || ch == '{')
        {//左括号入栈
            st.push(ch);
        }
        else
        {//右括号
            if (st.empty())
                return false;

            if (ch == ')')
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if (ch == ']')
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            else if (ch == '}')
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }
    }

    if (!st.empty())
        return false;

    return true;
}