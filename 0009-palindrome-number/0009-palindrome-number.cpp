class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers are not palindromes
        vector<int> t;
        int original = x;
        
        // Populate the vector with digits of the number
        while (x != 0) {
            t.push_back(x % 10);
            x = x / 10;
        }
        
        // Check if the number is a palindrome
        for (int i = 0; i < t.size() / 2; ++i) {
            if (t[i] != t[t.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};