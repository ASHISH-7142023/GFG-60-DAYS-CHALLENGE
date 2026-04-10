class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return {};

        int first = INT_MAX;
        int second = INT_MAX;

        // This variable helps us store the actual 'first'
        // that was associated with the current 'second'.
        int bestFirst = INT_MAX;

        for (int x : arr)
        {
            if (x <= first)
            {
                first = x;
            }
            else if (x <= second)
            {
                // x is greater than 'first', so it can be 'second'
                second = x;
                bestFirst = first;
            }
            else
            {
                // x is greater than 'second', which is greater than 'bestFirst'
                return {bestFirst, second, x};
            }
        }

        return {}; // No such subsequence found
    }
};