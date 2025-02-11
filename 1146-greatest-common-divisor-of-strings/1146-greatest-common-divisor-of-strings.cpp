class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
     if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);  // Ensure str1 is longer

        if (str1.find(str2) != 0) return "";  // If str2 is not a prefix of str1, return ""

        if (str2.empty()) return str1;  // Base case: when str2 becomes empty, return str1

        return gcdOfStrings(str1.substr(str2.size()), str2);   
    }
};