class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int,int>> nums_with_index;

        for(int i=0;i<nums.size();i++){
            nums_with_index.push_back({nums[i],i});
        }

        sort(nums_with_index.begin(),nums_with_index.end());

        int low = 0;
        int high = nums_with_index.size()-1;
        
        while(low<high){
            int sum = nums_with_index[low].first + nums_with_index[high].first;
            
            if(sum == target){
                return{nums_with_index[low].second , nums_with_index[high].second};
            }
            if(sum > target){
                high--;
            }
            if(sum < target){
                low++;
            }
        }
        return {-1,-1};
    }
};