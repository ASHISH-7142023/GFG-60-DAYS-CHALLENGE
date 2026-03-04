class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.length();
        int freq[26] = {0}, left = 0, maxLen = -1, distinctCount = 0;
        for (int right = 0; right < n; right++)
        {
            if (freq[s[right] - 'a'] == 0)
                distinctCount++;
            freq[s[right] - 'a']++;
            while (distinctCount > k)
            {
                int leftIdx = s[left] - 'a';
                freq[leftIdx]--;
                if (freq[leftIdx] == 0)
                    distinctCount--;
                left++;
            }
            if (distinctCount == k)
                maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};