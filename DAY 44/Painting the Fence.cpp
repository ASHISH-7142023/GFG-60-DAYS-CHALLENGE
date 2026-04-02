class Solution
{
public:
    int countWays(int n, int k)
    {
        // Base Cases
        if (n == 0)
            return 0;
        if (n == 1)
            return k;

        // For n = 2:
        // same: first and second are same (k ways)
        // diff: first and second are different (k * (k-1) ways)
        long long same = k;
        long long diff = (long long)k * (k - 1);
        long long total = same + diff;

        for (int i = 3; i <= n; i++)
        {
            same = diff;
            diff = (total * (k - 1));
            total = same + diff;
        }

        return (int)total;
    }
};