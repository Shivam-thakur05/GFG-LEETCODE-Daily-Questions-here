class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
      mp[s[i]]++;
    }
    int count = 0; // No characters included by default
    bool hasOdd = false;
    for (auto it : mp) {
      if (it.second % 2 == 0) {
        count += it.second; // Add even counts
      } else {
        hasOdd = true;  // Flag for a single odd character
        count += it.second - 1; // Include all but one odd character
      }
    }
    return count + hasOdd; // Add 1 for the middle character if there's an odd one
  }
};
