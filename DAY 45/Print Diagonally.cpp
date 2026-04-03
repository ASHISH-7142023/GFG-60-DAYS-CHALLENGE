class Solution
{
public:
    vector<int> diagView(vector<vector<int>> mat)
    {
        int n = mat.size();
        vector<int> result;

        // There are (2*n - 1) anti-diagonals in total
        for (int s = 0; s <= 2 * (n - 1); s++)
        {
            int i, j;

            // Determine starting point for the current sum 's'
            if (s < n)
            {
                i = 0;
                j = s;
            }
            else
            {
                i = s - (n - 1);
                j = n - 1;
            }

            // Traverse the diagonal from top-right to bottom-left
            while (i < n && j >= 0)
            {
                result.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        return result;
    }
};