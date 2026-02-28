class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int n = arr.size();
        int lastNonZeroIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                std::swap(arr[i], arr[lastNonZeroIndex]);
                lastNonZeroIndex++;
            }
        }
    }
};