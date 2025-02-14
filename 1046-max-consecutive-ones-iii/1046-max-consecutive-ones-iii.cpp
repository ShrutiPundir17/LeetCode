class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int l = 0, r = 0, cnt = 0, max_len = 0;
        
        while (r < nums.size()) {
            if (nums[r] == 0) cnt++;  
            
            while (cnt > k) {      
                if (nums[l] == 0) cnt--;
                l++;
            }
            
            max_len = max(max_len, r - l + 1);
            r++;
        }
        
        return max_len;  
    }
};