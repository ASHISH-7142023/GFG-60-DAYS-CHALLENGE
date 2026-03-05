class Solution
{
public:
    string minWindow(string &s, string &p)
    {
        int n = s.length();
        int m = p.length();
        if (m > n)
            return "";

        int req[256] = {0};
        int window[256] = {0};
        int uniqueInP = 0;

        for (char c : p)
        {
            if (req[(unsigned char)c] == 0)
                uniqueInP++;
            req[(unsigned char)c]++;
        }

        int left = 0, count = 0;
        int minLen = INT_MAX, startIdx = -1;

        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            window[(unsigned char)c]++;

            if (req[(unsigned char)c] > 0 && window[(unsigned char)c] == req[(unsigned char)c])
            {
                count++;
            }

            while (count == uniqueInP)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                if (req[(unsigned char)leftChar] > 0 && window[(unsigned char)leftChar] == req[(unsigned char)leftChar])
                {
                    count--;
                }
                window[(unsigned char)leftChar]--;
                left++;
            }
        }

        if (startIdx == -1)
            return "";
        return s.substr(startIdx, minLen);
    }
};