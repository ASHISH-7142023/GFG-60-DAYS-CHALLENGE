class Solution
{
public:
    int kBitFlips(vector<int> &arr, int k)
    {
        int n = arr.size();
        int totalFlips = 0;
        int currentFlipState = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                currentFlipState ^= isFlipped[i - k];
            }

            if (currentFlipState % 2 == arr[i])
            {
                if (i + k > n)
                {
                    return -1;
                }
                isFlipped[i] = 1;
                currentFlipState ^= 1;
                totalFlips++;
            }
        }

        return totalFlips;
    }
};