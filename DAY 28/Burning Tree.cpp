/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    Node *mapParents(Node *root, int target, unordered_map<Node *, Node *> &parentMap)
    {
        queue<Node *> q;
        q.push(root);
        Node *targetNode = nullptr;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
                targetNode = curr;

            if (curr->left)
            {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }

    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parentMap;
        Node *targetNode = mapParents(root, target, parentMap);

        if (!targetNode)
            return 0;

        queue<Node *> q;
        unordered_set<Node *> visited;

        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool burnedNew = false;

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && visited.find(curr->left) == visited.end())
                {
                    burnedNew = true;
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end())
                {
                    burnedNew = true;
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap.count(curr) && visited.find(parentMap[curr]) == visited.end())
                {
                    burnedNew = true;
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            if (burnedNew)
                time++;
        }

        return time;
    }
};