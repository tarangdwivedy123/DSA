class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_curr = nums[0];
        int max_global = nums [0];
        for(int i=1;i<nums.size();i++){
            max_curr = max(nums[i], max_curr+nums[i]);
            if(max_curr > max_global){
                max_global = max_curr;
            }
    }
    return max_global;
    }
};