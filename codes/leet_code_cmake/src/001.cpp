#include "subject.h"

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    //1.ÅÅÐò
    //2.Ë«Ö¸Õë
    vector<int> v_ret(2);
    if (nums.empty())
        return v_ret;

    multimap<int, int> map_nums;
    for (int i = 0; i < nums.size(); i++)
    {
        map_nums.insert(make_pair(nums[i], i));
    }

    auto iter_begin = map_nums.begin();
    auto iter_end = map_nums.end();
    --iter_end;
    int sum = 0;
    while (iter_begin != iter_end)
    {
        sum = iter_begin->first + iter_end->first;
        if (sum == target)
        {
            v_ret[0] = iter_begin->second;
            v_ret[1] = iter_end->second;
            return v_ret;
        }
        else if (sum < target)
        {
            iter_begin++;
        }
        else
        {
            iter_end--;
        }
    }

    return v_ret;
}