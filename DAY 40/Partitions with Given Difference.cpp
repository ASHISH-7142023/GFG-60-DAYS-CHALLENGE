class Solution
{
public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;

        // Validity checks
        if ((totalSum + diff) % 2 != 0 || totalSum < diff)
            return 0;

        int target = (totalSum + diff) / 2;
        int n = arr.size();
        int mod = 1e9 + 7;

        // dp[j] stores the number of ways to achieve sum j
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // Base case: one way to make sum 0 (empty set)

        for (int num : arr)
        {
            // Iterate backwards to ensure each element is used only once
            for (int j = target; j >= num; j--)
            {
                dp[j] = (dp[j] + dp[j - num]) % mod;
            }
        }

        return dp[target];
    }
};