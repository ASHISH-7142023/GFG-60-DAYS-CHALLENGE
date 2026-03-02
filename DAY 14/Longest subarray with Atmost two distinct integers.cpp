#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;
        unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < n; right++)
        {
            freq[arr[right]]++;
            while (freq.size() > 2)
            {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                {
                    freq.erase(arr[left]);
                }
                left++;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};