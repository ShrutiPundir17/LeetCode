class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
     if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);  
        if (str1.find(str2) != 0) return "";
        if (str2.empty()) return str1;  
        return gcdOfStrings(str1.substr(str2.size()), str2);   
    }
};