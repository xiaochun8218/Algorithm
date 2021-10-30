#include "subject.h"

bool isValid(string s)
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

void findSol(int pos, int total_pos, string& sol, vector<string>& v_res)
{
    //�ݹ����
    if (pos == total_pos)
    {
        //�ж�sol�Ƿ�Ϸ�
        if (isValid(sol))
        {
            v_res.emplace_back(sol);
        }
        return;
    }

    //�����ֳ�
    string sol_old = sol;

    //�������п�����
    for (size_t i = 0; i < 2; i++)
    {
        string ch = i == 0 ? "(" : ")";
        sol += ch;

        //�ݹ�
        findSol(pos + 1, total_pos, sol, v_res);

        //���ݣ���ԭ�ֳ�
        sol = sol_old;
    }
}

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> v_res;
    if (0 >= n)
        return v_res;

    //ȫ���� + �ж��Ƿ�Ϸ�
    string sol;
    findSol(0, 2 * n, sol, v_res);

    return v_res;
}