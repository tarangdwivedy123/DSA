class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j<strs.size();j++){
                if(i >= strs[j].size() ||strs[0][i] != strs[j][i]){
                    return prefix;
                }
            }
            prefix.push_back(strs[0][i]);
        }
        return prefix;
    }
};