class Solution
{
public:
    bool canFormPalindrome(string &s)
    {
        // Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Count occurrences of each character
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        int oddCount = 0;
        // Count how many characters have an odd frequency
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
            {
                oddCount++;
            }
        }

        // A palindrome can have at most one character with an odd frequency
        return oddCount <= 1;
    }
};