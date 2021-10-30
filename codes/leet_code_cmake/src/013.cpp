#include "subject.h"

int Solution::romanToInt(string s)
{
    int res = 0;

    //±éÀú
    vector<string> v_str_roman_ex = {"CM","CD","XC","XL","IX","IV"};
    vector<int> v_num_roman_ex = { 900,400,90,40,9,4 };

    vector<string> v_str_roman = { "M","D","C","L","X","V","I" };
    vector<int> v_num_roman = { 1000,500,100,50,10,5,1 };

    int i = 0;
    while (i < s.size())
    {
        string str_cur;
        str_cur.push_back(s[i]);
        string str_next;
        if (i+1 < s.size())
            str_next.push_back(s[i+1]);
        string cur_next = str_cur + str_next;

        auto iter_ex = std::find(v_str_roman_ex.begin(), v_str_roman_ex.end(), cur_next);
        if (iter_ex != v_str_roman_ex.end())
        {
            int pos = iter_ex - v_str_roman_ex.begin();
            res += v_num_roman_ex[pos];
            i += 2;
        }
        else
        {
            auto iter = std::find(v_str_roman.begin(), v_str_roman.end(), str_cur);
            int pos = iter - v_str_roman.begin();
            res += v_num_roman[pos];
            i++;
        }
    }

    return res;
}