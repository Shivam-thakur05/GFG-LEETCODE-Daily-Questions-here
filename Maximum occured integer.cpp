// Thought Approach (TLE)     S.C - O(n), T.C - O(n)^2

class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
    unordered_map<int,int>mp;
    int i = 0;
       while(i < n){
           for(int j = l[i]; j <= r[i]; ++j){
               mp[j]++;
           }
         i++;  
       }
       int ans = 0;
       int maxFreq = INT_MIN;
       int minElement = INT_MAX;
       for(auto it: mp){
           if(it.second > maxFreq){
               maxFreq = it.second;
               ans = it.first;
           } 
           //if frequency is same then take the minimum element
           else if(it.first < ans && it.second == maxFreq){
               ans = it.first;
           }
       }
       return ans;
    }
};


//Optimal Approach 
class Solution {
  public:
    // l and r are input arrays
    // maxx : maximum in r[]
    // n: size of array
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
        // Create an array to store the difference
        std::vector<int> arr(maxx + 2, 0);

        // Applying the difference array technique
        for (int i = 0; i < n; ++i) {
            arr[l[i]] += 1;
            arr[r[i] + 1] -= 1;
        }

        // Finding the prefix sum and the maximum occurred integer
        int maxCount = 0;
        int maxOccur = 0;
        int currentCount = 0;

        for (int i = 0; i <= maxx; ++i) {
            currentCount += arr[i];
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxOccur = i;
            }
        }

        return maxOccur;
    }
