#include "subject.h"

string Solution::longestCommonPrefix(vector<string>& strs)
{
    string str_res;

    //方法一
    //遍历计数
    /*
    map<int, unordered_map<char, int> > map_data;
    for (auto& iter : strs)
    {
        for (int i = 0; i < iter.size(); i++)
        {
            map_data[i][iter[i]]++;
        }
    }

    for (auto& iter_pos : map_data)
    {
        for (auto& iter : iter_pos.second)
        {
            if (iter.second == strs.size())
                str_res.push_back(iter.first);
            else
                return;
        }
    }
    */
    
    //方法二
    //使用string.find，返回不是0，删掉最后一个字符接着匹配
    str_res = strs.empty() ? "" : strs[0];
    for (auto& str : strs)
    {
        while (str.find(str_res) != 0)
        {
            str_res = str_res.substr(0, str_res.size() - 1);
        }

        if (str_res.empty())
            return str_res;
    }

    return str_res;
}