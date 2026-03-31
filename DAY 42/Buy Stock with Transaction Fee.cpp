class Solution
{
public:
    int maxProfit(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n <= 1)
            return 0;

        // Initial states for Day 0
        long hold = -arr[0]; // Bought the stock
        long free = 0;       // Did nothing

        for (int i = 1; i < n; i++)
        {
            // Maximum of (keep holding, or buy today)
            long next_hold = max(hold, free - arr[i]);

            // Maximum of (stay free, or sell today and pay fee)
            long next_free = max(free, hold + arr[i] - k);

            hold = next_hold;
            free = next_free;
        }

        // At the end, we want to be 'free' (no point holding stock on the last day)
        return (int)free;
    }
};