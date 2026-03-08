class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        bool present[1001] = {false};
        int max_val = 0;

        for (int x : arr)
        {
            present[x] = true;
            if (x > max_val)
                max_val = x;
        }

        for (int i = 1; i <= max_val; i++)
        {
            if (!present[i])
                continue;

            for (int j = i; j <= max_val; j++)
            {
                if (!present[j])
                    continue;

                int sum_sq = i * i + j * j;
                int c = sqrt(sum_sq);

                if (c * c == sum_sq && c <= 1000 && present[c])
                {
                    return true;
                }
            }
        }
        return false;
    }
};