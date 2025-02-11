class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    int m = word1.size(), n = word2.size();
        string ans;
        ans.reserve(m + n); 

        int i = 0, j = 0;
        while (i < m && j < n) {
            ans += word1[i++];
            ans += word2[j++];
        }
        if (i < m) ans.append(word1.begin() + i, word1.end());
        if (j < n) ans.append(word2.begin() + j, word2.end());

        return ans;   
    }
};