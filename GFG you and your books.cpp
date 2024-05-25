class Solution {
public:
    typedef long long ll;
    long long max_Books(int arr[], int n, int k) {
        ll tempAns = 0, realAns = 0;
        
        for (ll start = 0; start < n; start++) {
            if (arr[start] <= k) {
                tempAns += arr[start];
            } else {
                realAns = max(realAns, tempAns);
                tempAns = 0;
            }
        }
        // Final update in case the largest segment is at the end of the array
        realAns = max(realAns, tempAns);
        return realAns;
    }
};
