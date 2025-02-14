class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> unique1, unique2;
        unique1.reserve(s1.size());
        unique2.reserve(s2.size());

        for (int v : s1) {
            if (s2.find(v) == s2.end()) { // Avoids C++20 `.contains()`
                unique1.push_back(v);
            }
        }
        
        for (int v : s2) {
            if (s1.find(v) == s1.end()) {
                unique2.push_back(v);
            }
        }

        return {move(unique1), move(unique2)};   
    }
};