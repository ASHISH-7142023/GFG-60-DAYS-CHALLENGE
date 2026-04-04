class Solution
{
public:
    vector<string> graycode(int n)
    {
        // Base case: for n = 1, Gray code is "0" and "1"
        if (n == 1)
        {
            return {"0", "1"};
        }

        // Recursive step: get the Gray code for n-1
        vector<string> prev = graycode(n - 1);
        vector<string> result;

        // Step 1: Prefix "0" to the original sequence
        for (int i = 0; i < prev.size(); i++)
        {
            result.push_back("0" + prev[i]);
        }

        // Step 2: Prefix "1" to the reflected (reversed) sequence
        for (int i = prev.size() - 1; i >= 0; i--)
        {
            result.push_back("1" + prev[i]);
        }

        return result;
    }
};