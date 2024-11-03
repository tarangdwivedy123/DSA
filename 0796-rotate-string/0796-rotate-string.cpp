class Solution {
public:

    bool rotateString(string s, string goal) {
        for(char ele:s){
            if(!s.empty()){
            char firstEle = s.front();
            s.erase(s.begin());
            s.push_back(firstEle);
        }
            if( s == goal){
                return true;
            }
        }
        return false;
    }
};