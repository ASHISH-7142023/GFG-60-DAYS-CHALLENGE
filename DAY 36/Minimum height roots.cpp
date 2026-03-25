class Solution
{
public:
    vector<int> minHeightRoot(int V, vector<vector<int>> &edges)
    {
        if (V == 1)
            return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (degree[i] == 1)
            {
                q.push(i);
            }
        }

        int remainingNodes = V;
        while (remainingNodes > 2)
        {
            int leafCount = q.size();
            remainingNodes -= leafCount;

            for (int i = 0; i < leafCount; i++)
            {
                int leaf = q.front();
                q.pop();

                for (int neighbor : adj[leaf])
                {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};