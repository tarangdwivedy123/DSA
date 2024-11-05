class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 
        vector<int> t;
        int original = x;
        
       
        while (x != 0) {
            t.push_back(x % 10);
            x = x / 10;
        }
        
        for (int i = 0; i < t.size() / 2; ++i) {
            if (t[i] != t[t.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
