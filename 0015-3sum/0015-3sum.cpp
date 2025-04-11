
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1; // Two pointers
            while (j < k) {
                int curr_val = nums[i] + nums[j] + nums[k];
                if (curr_val == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;

                    // Skip duplicates for the second and third numbers
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                } else if (curr_val < 0) {
                    ++j; // Move the left pointer to increase the sum
                } else {
                    --k; // Move the right pointer to decrease the sum
                }
            }
        }

        return result;
    }
};