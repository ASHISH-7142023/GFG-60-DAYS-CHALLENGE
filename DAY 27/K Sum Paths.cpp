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
    int count = 0;
    unordered_map<long long, int> prefixSumMap;

    void solve(Node *root, int k, long long currentSum)
    {
        if (!root)
            return;

        currentSum += root->data;

        if (currentSum == k)
        {
            count++;
        }

        if (prefixSumMap.find(currentSum - k) != prefixSumMap.end())
        {
            count += prefixSumMap[currentSum - k];
        }

        prefixSumMap[currentSum]++;

        solve(root->left, k, currentSum);
        solve(root->right, k, currentSum);

        prefixSumMap[currentSum]--;
    }

    int countAllPaths(Node *root, int k)
    {
        count = 0;
        prefixSumMap.clear();
        solve(root, k, 0);
        return count;
    }
};