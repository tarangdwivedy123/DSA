class Solution {
public:
    int characterReplacement(string s, int k) {
         int max_len = 0;
    int max_count = 0;
    unordered_map<char, int> count;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        count[s[end]]++;
        max_count = max(max_count, count[s[end]]);

        while (end - start + 1 - max_count > k) {
            count[s[start]]--;
            start++;
        }

        max_len = max(max_len, end - start + 1);
    }

    return max_len;
    }
};