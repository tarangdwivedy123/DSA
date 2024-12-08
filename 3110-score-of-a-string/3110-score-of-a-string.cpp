class Solution {
public:
    int scoreOfString(string s) {
        int sumDump = 0;
        fot(int i=0;i<s.length()-1;i++){
            sumDumpo = sumDump + math.abs(s.charCodeAt(i)-s.charCodeAt(i+1));
        }
        return sumDump;
    }
};