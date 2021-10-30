#include "subject.h"

bool isValid(string s)
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

void findSol(int pos, int total_pos, string& sol, vector<string>& v_res)
{
    //递归出口
    if (pos == total_pos)
    {
        //判断sol是否合法
        if (isValid(sol))
        {
            v_res.emplace_back(sol);
        }
        return;
    }

    //保存现场
    string sol_old = sol;

    //遍历所有可能性
    for (size_t i = 0; i < 2; i++)
    {
        string ch = i == 0 ? "(" : ")";
        sol += ch;

        //递归
        findSol(pos + 1, total_pos, sol, v_res);

        //回溯，还原现场
        sol = sol_old;
    }
}

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> v_res;
    if (0 >= n)
        return v_res;

    //全排列 + 判断是否合法
    string sol;
    findSol(0, 2 * n, sol, v_res);

    return v_res;
}