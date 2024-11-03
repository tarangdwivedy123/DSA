class Solution {
public:
        int result = INT_MAX;
        auto sumOfDgits(int num){
            int sum = 0;
            while(num !=0){
                sum = sum + num%10;
                num = num/10;
            }

            if(result > sum){
                result = sum;
            }
        }

    int minElement(vector<int>& nums) {
      
        for(int num:nums){
            sumOfDgits(num);
        }

        return result;
        

    }
};