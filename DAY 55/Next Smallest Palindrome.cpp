class Solution
{
public:
    vector<int> nextPalindrome(vector<int> &num)
    {
        int n = num.size();

        // Case 1: Check if all digits are 9
        bool allNine = true;
        for (int x : num)
        {
            if (x != 9)
            {
                allNine = false;
                break;
            }
        }
        if (allNine)
        {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }

        // Case 2 & 3: Standard Palindrome Logic
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2 == 0) ? mid : mid + 1;

        // Skip digits that are already equal in mirrored positions
        while (i >= 0 && num[i] == num[j])
        {
            i--;
            j++;
        }

        bool leftSmaller = false;
        // Determine if mirroring the left half makes the number smaller
        if (i < 0 || num[i] < num[j])
        {
            leftSmaller = true;
        }

        // Mirror the left half to the right half
        vector<int> res = num;
        i = mid - 1;
        j = (n % 2 == 0) ? mid : mid + 1;
        while (i >= 0)
        {
            res[j++] = res[i--];
        }

        // If the mirrored version was smaller or equal, increment the middle
        if (leftSmaller)
        {
            int carry = 1;
            i = (n % 2 == 0) ? mid - 1 : mid;

            while (i >= 0 && carry > 0)
            {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;
                i--;
            }

            // Mirror the incremented left half back to the right
            i = mid - 1;
            j = (n % 2 == 0) ? mid : mid + 1;
            while (i >= 0)
            {
                res[j++] = res[i--];
            }
        }

        return res;
    }
};