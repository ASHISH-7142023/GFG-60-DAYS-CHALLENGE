class Solution
{
public:
    int catalan(int n)
    {
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }

    vector<int> countBSTs(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int leftCount = 0;
            int rightCount = 0;

            for (int j = 0; j < n; j++)
            {
                if (arr[j] < arr[i])
                    leftCount++;
                if (arr[j] > arr[i])
                    rightCount++;
            }

            result[i] = catalan(leftCount) * catalan(rightCount);
        }

        return result;
    }
};