#include "subject.h"

bool Solution::isValid(string s)
{
    if (s.empty())
        return true;

    //1.���������ţ���ջ
    //2.���������ţ���ջ��Ԫ��ƥ��
    //  a.ƥ�����ˣ���ջ������ƥ��
    //  b.ûƥ���ϣ�return false
    std::stack<char> st;
    for (size_t i = 0; i < s.size(); i++)
    {
        char ch = s.at(i);
        if (ch == '(' || ch == '[' || ch == '{')
        {//��������ջ
            st.push(ch);
        }
        else
        {//������
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