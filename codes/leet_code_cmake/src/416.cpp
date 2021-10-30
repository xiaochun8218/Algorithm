#include "leet_code_common.h"

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums)
        sum += num;
    if (sum % 2 != 0)
        return false;
    int n = nums.size();
    sum /= 2;
    vector<vector<int> > dp(n + 1, vector<int>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - nums[i - 1] < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
    }
    return dp[n][sum];
}
