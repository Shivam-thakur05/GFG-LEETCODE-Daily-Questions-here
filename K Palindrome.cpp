class Solution{
public:
    int kPalindrome(string s, int n, int k)
    {
        // code here
        string t = s;
        reverse(t.begin() , t.end());
        int m = n;
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        for(int idx1 = 1 ; idx1<=m ; ++idx1){
            for(int idx2 = 1 ; idx2<=n ; ++idx2){
                if(s[idx1-1] == t[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }
                else dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
            }
        }
        int lcss =  dp[m][n];
        // return lcss;
        int num = n - lcss;
        if(num <= k)return 1;
        return 0;
    }
};
