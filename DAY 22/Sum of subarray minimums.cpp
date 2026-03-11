class Solution
{
public:
    int sumSubMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        unsigned int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += (unsigned int)arr[i] * left[i] * right[i];
        }

        return (int)totalSum;
    }
};