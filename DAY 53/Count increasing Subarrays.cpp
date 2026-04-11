class Solution
{
public:
    int countIncreasing(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 2)
            return 0;

        int count = 0;
        int len = 1; // Current length of increasing sequence

        for (int i = 0; i < n - 1; i++)
        {
            // Check if the next element continues the increasing sequence
            if (arr[i + 1] > arr[i])
            {
                len++;
            }
            else
            {
                // Sequence broke, add calculated subarrays to total
                if (len >= 2)
                {
                    count += (len * (len - 1)) / 2;
                }
                len = 1; // Reset length for the next potential sequence
            }
        }

        // Final check for a sequence that might end at the last index
        if (len >= 2)
        {
            count += (len * (len - 1)) / 2;
        }

        return count;
    }
};
