class Solution
{
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
    {
        int n = arr1.size();
        int m = arr2.size();

        int left = 0;
        int right = m - 1;

        long long min_diff = LLONG_MAX;
        vector<int> res(2);

        while (left < n && right >= 0)
        {
            int sum = arr1[left] + arr2[right];
            if (abs(sum - x) < min_diff)
            {
                min_diff = abs(sum - x);
                res[0] = arr1[left];
                res[1] = arr2[right];
            }
            if (sum > x)
            {
                right--;
            }
            else if (sum < x)
            {
                left++;
            }
            else
            {
                return {arr1[left], arr2[right]};
            }
        }

        return res;
    }
};