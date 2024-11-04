class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        // Preallocate string capacity to avoid reallocations
        string ans;
        ans.reserve(word.length() * 2);  // Maximum possible size
        
        int n = word.length();
        int i = 0;
        
        while (i < n) {
            char ch = word[i];
            int count = 1;
            
            // Count consecutive characters
            while (i + 1 < n && count < 9 && word[i] == word[i + 1]) {
                count++;
                i++;
            }
            
            // Append count and character directly without intermediate string operations
            ans += (count + '0');
            ans += ch;
            i++;
        }
        
        return ans;
    }
};
