#include "subject.h"

void findSol(string& digits, int n, int i, map<char, vector<string> >& map_num_str, string& str_sol, vector<string>& v_res)
{
    //递归出口
    if (i == n)
    {
        v_res.emplace_back(str_sol);
        return;
    }

    //保存现场
    string str_sol_old = str_sol;
    //遍历所有可能性
    char ch = digits.at(i);
    int col = map_num_str[ch].size();
    for (int j = 0; j < col; j++)
    {
        str_sol += map_num_str[ch][j];
        //递归
        findSol(digits, n, i+1, map_num_str, str_sol, v_res);

        //还原现场
        str_sol = str_sol_old;
    }
}

vector<string> Solution::letterCombinations(string digits)
{
    vector<string> v_res;
    if (digits.empty())
        return v_res;

    map<char, vector<string> > map_num_str;
    map_num_str['2'] = { "a", "b", "c" };
    map_num_str['3'] = { "d", "e", "f" };
    map_num_str['4'] = { "g", "h", "i" };
    map_num_str['5'] = { "j", "k", "l" };
    map_num_str['6'] = { "m", "n", "o" };
    map_num_str['7'] = { "p", "q", "r", "s" };
    map_num_str['8'] = { "t", "u", "v" };
    map_num_str['9'] = { "w", "x", "y", "z" };

    int n = digits.size();
    string sol_one;
    findSol(digits, n , 0, map_num_str, sol_one, v_res);

    return v_res;
}