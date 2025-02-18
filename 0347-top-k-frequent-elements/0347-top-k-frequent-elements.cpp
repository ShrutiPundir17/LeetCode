class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : cnt) {
            buckets[freq].push_back(num);
        }

        vector<int> ans;
        for (int i = nums.size(); i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }
        
        return ans;
    }
};
