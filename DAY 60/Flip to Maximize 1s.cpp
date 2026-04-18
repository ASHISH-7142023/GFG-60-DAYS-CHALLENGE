class Solution
{
public:
    int maxOnes(vector<int> &arr)
    {
        int n = arr.size();
        int initialOnes = 0;

        // Count total 1s already present
        for (int x : arr)
        {
            if (x == 1)
                initialOnes++;
        }

        int max_gain = 0;
        int current_gain = 0;

        for (int i = 0; i < n; i++)
        {
            // If arr[i] is 0, flipping it gives +1 gain
            // If arr[i] is 1, flipping it gives -1 gain
            int val = (arr[i] == 0) ? 1 : -1;

            current_gain += val;

            // Kadane's logic: if current gain drops below 0, reset
            if (current_gain < 0)
            {
                current_gain = 0;
            }

            // Track the maximum gain found so far
            if (current_gain > max_gain)
            {
                max_gain = current_gain;
            }
        }

        // Maximum 1s = Original 1s + best gain from flipping
        return initialOnes + max_gain;
    }
};