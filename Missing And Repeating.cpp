
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> ans(2); // ans[0] for the repeating element, ans[1] for the missing element
        
        // Count occurrences of each element
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        // Find the repeating and missing numbers
        for (int i = 1; i <= arr.size(); i++) {
            if (mp[i] == 0) {
                ans[1] = i; // Missing element
            }
            if (mp[i] > 1) {
                ans[0] = i; // Repeating element
            }
        }
        
        return ans;
    }
};
