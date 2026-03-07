class Solution
{
public:
    long long noOfWays(int m, int n, int x)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                for (int f = 1; f <= m && f <= j; f++)
                {
                    dp[i][j] += dp[i - 1][j - f];
                }
            }
        }

        return dp[n][x];
    }
};