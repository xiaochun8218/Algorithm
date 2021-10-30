#include "subject.h"

string Solution::convert(string s, int numRows)
{
    if (numRows == 0)
        return "";
    if (numRows == 1)
        return s;

    //1.i == 0£¬j ²»±ä£¬i++
    //2.i == numRows - 1, i--,j++
    vector<vector<char> > v_data(numRows);
    int i = 0, j = 0;
    int direction = 0;
    for (int pos = 0; pos < s.size(); pos++)
    {
        v_data[i].push_back(s.at(pos));

        if (i == 0)
            direction = 1;
        else if (i == numRows - 1)
            direction = -1;

        if (direction == 1)
        {
            i++;
        }
        else if (direction == -1)
        {
            i--;
            j++;
        }
    }

    string str_res;
    for (int r = 0; r < numRows; r++)
    {
        for (auto& iter : v_data[r])
        {
            str_res.push_back(iter);
        }
    }

    return str_res;
}