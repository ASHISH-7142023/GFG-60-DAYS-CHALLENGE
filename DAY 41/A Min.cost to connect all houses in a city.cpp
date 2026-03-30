class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {
        int n = houses.size();
        if (n == 0)
            return 0;

        // Priority queue stores {cost, house_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(n, false);

        pq.push({0, 0});
        int totalCost = 0;
        int count = 0;

        while (count < n && !pq.empty())
        {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // If the house is already in the MST, ignore it
            if (inMST[u])
                continue;

            inMST[u] = true;
            totalCost += cost;
            count++;

            for (int v = 0; v < n; v++)
            {
                if (!inMST[v])
                {
                    // Manhattan distance: |x1 - x2| + |y1 - y2|
                    int dist = abs(houses[u][0] - houses[v][0]) +
                               abs(houses[u][1] - houses[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};