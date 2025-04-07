class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      
      vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.push_back({nums[i], i});
        }
      sort(numWithIndex.begin(), numWithIndex.end());

      int low = 0;
      int high = nums.size()-1;
      while(low<high){
        int sum = numWithIndex[low].first + numWithIndex[high].first;
        if(sum == target){
             return {numWithIndex[low].second, numWithIndex[high].second};
        }else if(sum > target){
             high--;
        }
        else if(sum < target){
            low++;
        }
      }

      return{-1,-1};

    }
};