#include "subject.h"

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
    vector<vector<int>> v_res;
    //1.遍历一遍，转为两数之和求解:排序+双指针
    //2.去重：nums[i]和nums[i+1]相同的情况
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i >= 1 && nums[i] == nums[i - 1])
            continue;
        int left = i+1; 
        int right = n - 1;
        while (left < right)
        {
            if (left >= i+2 &&nums[left] == nums[left - 1])
            {
                left++;
                continue;
            }
            int sum = nums[left] + nums[right] + nums[i];
            if (0 == sum)
            {
                vector<int> v_one;
                v_one.emplace_back(nums[i]);
                v_one.emplace_back(nums[left]);
                v_one.emplace_back(nums[right]);
                v_res.emplace_back(v_one);
                left++;
            }
            else if (0 < sum)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    return v_res;
}