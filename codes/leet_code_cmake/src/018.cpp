#include "subject.h"

vector<vector<int> > Solution::fourSum(vector<int>& nums, int target)
{
    vector<vector<int> > vec_res;
    if (nums.empty())
        return vec_res;

    //1.排序
    sort(nums.begin(), nums.end());

    //2.选两个数，然后转换成2数之和求解
    //去重
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i >= 1 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j >= i + 2 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                if (left >= j + 2 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }

                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    vector<int> vec_one;
                    vec_one.emplace_back(nums[i]);
                    vec_one.emplace_back(nums[j]);
                    vec_one.emplace_back(nums[left]);
                    vec_one.emplace_back(nums[right]);
                    vec_res.emplace_back(vec_one);
                    left++;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    
    return vec_res;
}