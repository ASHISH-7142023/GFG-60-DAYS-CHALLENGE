/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;

        map<int, int> topNodeMap;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();

            Node *curr = p.first;
            int hd = p.second;

            if (topNodeMap.find(hd) == topNodeMap.end())
            {
                topNodeMap[hd] = curr->data;
            }

            if (curr->left)
            {
                q.push({curr->left, hd - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, hd + 1});
            }
        }

        for (auto const &[hd, val] : topNodeMap)
        {
            result.push_back(val);
        }

        return result;
    }
};
