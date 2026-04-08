class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            // Move left pointer while we see 0s
            while (arr[left] == 0 && left < right)
            {
                left++;
            }

            // Move right pointer while we see 1s
            while (arr[right] == 1 && left < right)
            {
                right--;
            }

            // If left is still less than right, swap the 1 at left with 0 at right
            if (left < right)
            {
                arr[left] = 0;
                arr[right] = 1;
                left++;
                right--;
            }
        }
    }
};