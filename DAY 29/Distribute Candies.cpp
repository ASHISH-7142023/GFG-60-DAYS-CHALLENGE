/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    int totalMoves = 0;

    int solve(Node *root)
    {
        if (!root)
            return 0;

        int leftBalance = solve(root->left);
        int rightBalance = solve(root->right);

        totalMoves += abs(leftBalance) + abs(rightBalance);

        return root->data + leftBalance + rightBalance - 1;
    }

    int distCandy(Node *root)
    {
        totalMoves = 0;
        solve(root);
        return totalMoves;
    }
};