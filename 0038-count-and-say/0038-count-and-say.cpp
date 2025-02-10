class Solution {
public:
    string countAndSay(int n) {
       string s = "1";
        while (--n) {
            ostringstream oss;
            int len = s.size();
            for (int i = 0; i < len; ) {
                int count = 1;
                while (i + count < len && s[i] == s[i + count]) ++count;
                oss << count << s[i]; // Append count and character
                i += count;
            }
            s = oss.str(); // Convert stream to string
        }
        return s;    
    }
};