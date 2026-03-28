class Solution
{
public:
    void dfs(int u, int p, int &timer, vector<int> adj[], vector<int> &disc,
             vector<int> &low, vector<bool> &isAP, vector<bool> &visited)
    {

        visited[u] = true;
        disc[u] = low[u] = ++timer;
        int children = 0;

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            if (visited[v])
            {
                // Back-edge found: update low value of current node
                low[u] = min(low[u], disc[v]);
            }
            else
            {
                // Tree-edge: recurse into child
                children++;
                dfs(v, u, timer, adj, disc, low, isAP, visited);

                low[u] = min(low[u], low[v]);

                // Check condition for non-root articulation point
                if (p != -1 && low[v] >= disc[u])
                {
                    isAP[u] = true;
                }
            }
        }

        // Special check for the root of the DFS tree
        if (p == -1 && children > 1)
        {
            isAP[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, 0), low(V, 0);
        vector<bool> visited(V, false), isAP(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, timer, adj, disc, low, isAP, visited);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++)
        {
            if (isAP[i])
                result.push_back(i);
        }

        if (result.empty())
            return {-1};
        return result;
    }
};