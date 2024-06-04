#include <algorithm> // Include this to use reverse function

class Solution {
public:
    string binaryNextNumber(string s) {
        int n = s.length();
        int carry = 1; // Start with carry = 1 as we are incrementing the binary number
        string ans = "";
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1' && carry == 1) {
                ans += '0';
                carry = 1;
            } else if (s[i] == '0' && carry == 1) {
                ans += '1';
                carry = 0;
            } else {
                ans += s[i];
            }
        }
        
        if (carry == 1) {
            ans += '1';
        }
        
        // Reverse the result to get the correct order
        reverse(ans.begin(), ans.end());
        
        // Remove leading zeros
        size_t first_non_zero = ans.find_first_not_of('0');
        if (first_non_zero != string::npos) {
            ans = ans.substr(first_non_zero);
        } else {
            ans = "0"; // If all are zeros, return "0"
        }
        
        return ans;
    }
};
