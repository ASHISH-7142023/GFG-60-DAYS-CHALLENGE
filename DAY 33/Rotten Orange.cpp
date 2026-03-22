class Solution
{
public:
    int orangesRot(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (mat[i][j] == 1)
                {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0)
            return 0;

        int minutes = 0;
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int size = q.size();
            bool rottedThisTurn = false;

            for (int i = 0; i < size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int nrow = r + dRow[j];
                    int ncol = c + dCol[j];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1)
                    {
                        mat[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        freshCount--;
                        rottedThisTurn = true;
                    }
                }
            }
            if (rottedThisTurn)
                minutes++;
        }

        return (freshCount == 0) ? minutes : -1;
    }
};
