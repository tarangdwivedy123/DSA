class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int minimum = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] < minimum) {minimum = nums[mid];}
                if(nums[low]<=nums[mid]){
                    if(nums[low]<minimum){minimum = nums[low];}
                    low = mid+1;
                }
                else{
                    if(nums[mid+1]<minimum){
                        minimum = nums[mid];
                    }
                    high = mid-1;
                }
        }   
        return minimum;
    }
};