class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i=i+2){
            int y= nums[i];
            while(y){
                arr.push_back(nums[i+1]);
                y--;
            }
        }
        return arr;
    }
};