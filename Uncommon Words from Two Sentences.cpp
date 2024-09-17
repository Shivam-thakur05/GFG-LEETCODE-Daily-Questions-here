class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string temp = "";

        // Process sentence s1
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ') temp += s1[i];
            else {
                mp[temp]++;
                temp = "";
            }
        }
        // Don't forget to add the last word of s1
        if (!temp.empty()) {
            mp[temp]++;
        }

        temp = "";
        // Process sentence s2
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] != ' ') temp += s2[i];
            else {
                mp[temp]++;
                temp = "";
            }
        }
        // Don't forget to add the last word of s2
        if (!temp.empty()) {
            mp[temp]++;
        }

        // Collect uncommon words
        for (auto it : mp) {
            if (it.second == 1) ans.push_back(it.first);
        }

        return ans;
    }
};
