class Solution
{
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women)
    {
        int n = men.size();

        // womanPartner[i] stores the index of the man currently engaged to woman i
        // Initialize with -1 (free)
        vector<int> womanPartner(n, -1);

        // manPartner[i] stores the index of the woman currently engaged to man i
        vector<int> manPartner(n, -1);

        // nextProposal[i] tracks the index of the next woman man i should propose to
        vector<int> nextProposal(n, 0);

        // To achieve O(1) lookup for woman's preferences:
        // womanPrefRank[w][m] = rank of man m in woman w's list (lower is better)
        vector<vector<int>> womanPrefRank(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                womanPrefRank[i][women[i][j]] = j;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++)
            freeMen.push(i);

        while (!freeMen.empty())
        {
            int m = freeMen.front();

            // Get the next woman man 'm' prefers
            int w = men[m][nextProposal[m]++];

            if (womanPartner[w] == -1)
            {
                // Woman is free, engage them
                womanPartner[w] = m;
                manPartner[m] = w;
                freeMen.pop();
            }
            else
            {
                // Woman is already engaged to m1
                int m1 = womanPartner[w];

                // If woman prefers m over her current partner m1
                if (womanPrefRank[w][m] < womanPrefRank[w][m1])
                {
                    womanPartner[w] = m;
                    manPartner[m] = w;
                    manPartner[m1] = -1; // m1 is now free

                    freeMen.pop();
                    freeMen.push(m1);
                }
                // Else, m remains free and stays in the queue to propose to his next choice
            }
        }

        return manPartner;
    }
};