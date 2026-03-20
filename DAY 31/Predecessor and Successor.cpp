/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = nullptr;
        Node *suc = nullptr;

        Node *curr = root;

        // Finding Successor: Smallest value > key
        while (curr)
        {
            if (curr->data > key)
            {
                suc = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        // Finding Predecessor: Largest value < key
        curr = root;
        while (curr)
        {
            if (curr->data < key)
            {
                pre = curr;
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        return {pre, suc};
    }
};