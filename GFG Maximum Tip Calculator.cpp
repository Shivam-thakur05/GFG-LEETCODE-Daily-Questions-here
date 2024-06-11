class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<long long, int>> tip_diff;
        long long tipA = 0;
        long long tipB = 0;
        int maxServeA = x;
        int maxServeB = y;
        for(int i = 0 ; i < n; i++)
        {
            long long diff = abs(arr[i] - brr[i]);
            tip_diff.push_back(pair<long long , int>(diff, i));
        }
        sort(tip_diff.begin(), tip_diff.end(), greater<pair<long long, int>>());
        /*for (auto x : tip_diff)
        {
            cout<< x.first<<" - "<<x.second<<endl;
        }*/
        for (auto a: tip_diff)
        {
            if (maxServeA > 0 && maxServeB > 0)
            {
                if (arr[a.second]>=brr[a.second])
                {
                    tipA += arr[a.second];
                    maxServeA--;
                }
                else if(maxServeB > 0)
                {
                    tipB += brr[a.second];
                    maxServeB--;
                }
            }
            else if (maxServeB > 0)
            {
                tipB += brr[a.second];
                maxServeB--;
            }
            else if (maxServeA > 0)
            {
                tipA += arr[a.second];
                maxServeA--;
            }
            else
            {
                break;
            }
        }
        return (long long) tipA+tipB;
    }
};
