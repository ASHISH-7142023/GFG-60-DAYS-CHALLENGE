class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        vector<int> result;
        int i = 0, j = 0;
        int n = a.size();
        int m = b.size();

        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else if (a[i] > b[j])
            {
                j++;
            }
            else
            {
                // Elements are equal, we found an intersection candidate
                // Check if it's already in the result to maintain distinct elements
                if (result.empty() || result.back() != a[i])
                {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        return result;
    }
};