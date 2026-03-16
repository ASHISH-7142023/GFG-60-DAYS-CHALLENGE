/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        map<int, vector<int>> hdMap;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *curr = temp.first;
            int hd = temp.second;

            hdMap[hd].push_back(curr->data);

            if (curr->left)
            {
                q.push({curr->left, hd - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, hd + 1});
            }
        }

        for (auto const &[hd, nodes] : hdMap)
        {
            result.push_back(nodes);
        }

        return result;
    }
};