class Solution
{
public:
    int countSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nse[i] = st.top();
            }
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            total += (nse[i] - i);
        }

        return (int)total;
    }
};