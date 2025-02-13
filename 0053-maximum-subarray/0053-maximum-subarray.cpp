class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     if (nums.empty()) 
            return 0;

        int maxSum = nums[0];
        int currentMax = nums[0];

        for (size_t i = 1; i < nums.size(); i++) { 
            currentMax = std::max(nums[i], nums[i] + currentMax);
            maxSum = std::max(maxSum, currentMax);
        }

        return maxSum;   
    }
};