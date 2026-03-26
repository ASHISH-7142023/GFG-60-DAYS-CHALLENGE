class Solution
{
public:
    int countPaths(int V, vector<vector<int>> &edges)
    {
        long long mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(V, LLONG_MAX);
        vector<long long> ways(V, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int time = neighbor.second;

                if (dist[u] + time < dist[v])
                {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (dist[u] + time == dist[v])
                {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return (int)(ways[V - 1] % mod);
    }
};