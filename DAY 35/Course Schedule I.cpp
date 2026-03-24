class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto &pre : prerequisites)
        {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;

            for (int nextCourse : adj[curr])
            {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0)
                {
                    q.push(nextCourse);
                }
            }
        }

        return count == n;
    }
};