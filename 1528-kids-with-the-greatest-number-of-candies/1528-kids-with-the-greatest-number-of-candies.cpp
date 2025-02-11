class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (int candyCount : candies) {
            result.push_back(candyCount + extraCandies >= maxCandies);
        }
        return result; 
    }
};