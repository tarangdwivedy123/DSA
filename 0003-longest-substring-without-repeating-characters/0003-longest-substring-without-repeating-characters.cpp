class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        unordered_map<char, int> hMap;
        int l = 0;
        int r = 0;
        int maxLen = 0;

        while (r < s.size()) {
            if (hMap.find(s[r]) != hMap.end() && hMap[s[r]] >= l) {
                l = hMap[s[r]] + 1;
            }
            hMap[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};