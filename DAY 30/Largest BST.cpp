/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct NodeValue
{
    int minNode, maxNode, maxSize;
    bool isBST;
};

class Solution
{
public:
    NodeValue solve(Node *root)
    {
        if (!root)
        {
            return {INT_MAX, INT_MIN, 0, true};
        }

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        if (left.isBST && right.isBST && root->data > left.maxNode && root->data < right.minNode)
        {
            int currentSize = 1 + left.maxSize + right.maxSize;
            return {
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                currentSize,
                true};
        }

        return {0, 0, max(left.maxSize, right.maxSize), false};
    }

    int largestBst(Node *root)
    {
        return solve(root).maxSize;
    }
};