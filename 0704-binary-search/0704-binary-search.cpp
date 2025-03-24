class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low  = 0;
        int mid = (low + high)/2;
        
        while(high>=low){
            if(target == nums[mid]) return mid; 
            else if(target > nums[mid]) { low = mid+1; mid= (low+high)/2;}
            else high = mid-1; mid= (low+high)/2;
        }

        return -1; 

    }
};