class Solution
{
public:
    string removeSpaces(string &s)
    {
        int count = 0; // Pointer for the next non-space character

        for (int i = 0; i < s.length(); i++)
        {
            // If the current character is not a space, move it forward
            if (s[i] != ' ')
            {
                s[count++] = s[i];
            }
        }

        // Remove the leftover characters at the end of the string
        s.erase(count);

        return s;
    }
};