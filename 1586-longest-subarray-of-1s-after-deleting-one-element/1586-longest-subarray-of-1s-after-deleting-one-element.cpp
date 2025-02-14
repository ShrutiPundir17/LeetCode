class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     int l = 0, r = 0, zero_count = 0, max_len = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) zero_count++;  
            
            while (zero_count > 1) { 
                if (nums[l] == 0) zero_count--;
                l++;
            }

            max_len = max(max_len, r - l);
            r++;
        }

        return max_len;    
    }
};