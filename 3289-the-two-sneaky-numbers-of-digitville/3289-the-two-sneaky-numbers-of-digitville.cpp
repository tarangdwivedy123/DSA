class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> keysWithValueTwo;
        unordered_map<int,int> freqMapp;
        for(int num : nums){
            freqMapp[num]++;
        }
        for(auto& pair : freqMapp){
            if(pair.second == 2){
                keysWithValueTwo.push_back(pair.first);
            }
        }
        return keysWithValueTwo;
    }
        
};