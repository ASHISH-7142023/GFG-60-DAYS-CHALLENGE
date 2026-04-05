class Solution
{
public:
    int totalWays(vector<int> &arr, int target)
    {
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;

        // Mathematical impossibility checks
        if ((totalSum + target) % 2 != 0 || totalSum < abs(target))
        {
            return 0;
        }

        int subsetTarget = (totalSum + target) / 2;
        int n = arr.size();

        // dp[j] stores the number of ways to achieve sum j
        vector<int> dp(subsetTarget + 1, 0);
        dp[0] = 1; // Base case: one way to make sum 0 (empty subset)

        for (int num : arr)
        {
            // Iterate backwards to avoid using the same element twice
            for (int j = subsetTarget; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetTarget];
    }
};