#include "subject.h"

int Solution::threeSumClosest(vector<int>& nums, int target)
{
    int64_t res_num = INT32_MAX;
    if (nums.empty())
        return res_num;

    //1.����
    std::sort(nums.begin(), nums.end());

    //2.������תΪ2��֮��
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            res_num = abs(sum - target) < abs(res_num - target) ? sum : res_num;
            if (sum == target)
            {
                return sum;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    //3.������ӽ���3��֮��
    return res_num;
}