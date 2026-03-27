class Solution
{
public:
    int n, m;
    int dp[71][71][71];

    int solve(int i, int j1, int j2, vector<vector<int>> &grid)
    {
        // Boundary check
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        {
            return -1e9;
        }

        // Base Case: Last row
        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        // Both robots have 3 possible moves, total 9 combinations
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int chocolates = 0;
                if (j1 == j2)
                    chocolates = grid[i][j1];
                else
                    chocolates = grid[i][j1] + grid[i][j2];

                int next = solve(i + 1, j1 + dj1, j2 + dj2, grid);
                maxi = max(maxi, chocolates + next);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int maxChocolate(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m - 1, grid);
    }
};