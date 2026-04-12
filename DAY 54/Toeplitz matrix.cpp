class Solution
{
public:
    bool isToeplitz(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Start from the second row and second column (index 1,1)
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // Compare current element with its top-left neighbor
                if (mat[i][j] != mat[i - 1][j - 1])
                {
                    return false;
                }
            }
        }

        // If no mismatches are found, it's a Toeplitz matrix
        return true;
    }
};