#include "subject.h"

vector<string> v_base = { "I", "X", "C", "M" };
vector<string> v_ex   = { "V", "L", "D" };

string pos_num_to_roman_base(int pos, int pos_num)
{
    string str_res;

    if (5 == pos_num)
        str_res = v_ex[pos];
    else if (pos_num < 5)
    {
        if (4 == pos_num)
            str_res = v_base[pos] + v_ex[pos];
        else
        {
            for (int i = 0; i < pos_num; i++)
            {
                str_res += v_base[pos];
            }
        }
    }
    else
    {
        if (9 == pos_num)
            str_res = v_base[pos] + v_base[pos + 1];
        else
        {
            str_res = v_ex[pos];
            for (int i = 5; i < pos_num; i++)
            {
                str_res += v_base[pos];
            }
        }
    }
    
    return str_res;
}

string pos_num_to_roman(int pos, int pos_num)
{
    string res;
    //����ʮ����
    if (pos < 3)
        res = pos_num_to_roman_base(pos, pos_num);
    else
    {
        for (int i = 0; i < pos_num; i++)
        {
            res += v_base[pos];
        }
    }

    return res;
}

string Solution::intToRoman(int num)
{
    string str_res;

    //����һ
    //��λ�滻 ����ʮ���١�ǧ
    /*
    int pos = 0;
    while (num > 0)
    {
        int pos_num = num % 10;

        str_res = pos_num_to_roman(pos, pos_num) + str_res;

        num /= 10;
        pos++;
    }
    */

    //������  
    //̰���㷨:ÿһ��ö�����п��ܽ⣬ȡ���Ž�
    vector<string> v_str_roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> v_num_roman = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    int i = 0;
    while (num > 0)
    {
        if (num >= v_num_roman[i])
        {
            str_res += v_str_roman[i];
            num -= v_num_roman[i];
        }
        else
        {
            i++;
        }
    }

    return str_res;
}