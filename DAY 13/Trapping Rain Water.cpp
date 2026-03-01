class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;

        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while (left <= right)
        {
            if (arr[left] <= arr[right])
            {
                if (arr[left] >= left_max)
                {
                    left_max = arr[left];
                }
                else
                {
                    total_water += left_max - arr[left];
                }
                left++;
            }
            else
            {
                if (arr[right] >= right_max)
                {
                    right_max = arr[right];
                }
                else
                {
                    total_water += right_max - arr[right];
                }
                right--;
            }
        }
        return total_water;
    }
};