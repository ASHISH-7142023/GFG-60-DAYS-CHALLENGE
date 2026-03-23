class Solution
{
public:
    int longestCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> adj(V, -1);
        for (auto &edge : edges)
        {
            adj[edge[0]] = edge[1];
        }

        vector<int> visited(V, 0);
        int maxCycleLen = -1;

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
                continue;

            // map to store {node: step_count_in_current_path}
            unordered_map<int, int> dist;
            int curr = i;
            int step = 0;

            while (curr != -1)
            {
                // If we hit a node in the CURRENT path, we found a cycle
                if (dist.count(curr))
                {
                    maxCycleLen = max(maxCycleLen, step - dist[curr]);
                    break;
                }

                // If we hit a node visited in a PREVIOUS traversal, no cycle here
                if (visited[curr])
                    break;

                visited[curr] = 1;
                dist[curr] = step++;
                curr = adj[curr];
            }
        }

        return maxCycleLen;
    }
};