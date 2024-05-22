class Solution {
  public:
    bool isPossible(vector<int> &stations, double mid, int k){
        int total = 0;
        for(int i = 1; i < stations.size(); i++){
            int dis = stations[i]-stations[i-1];
            total += ceil(dis/mid)-1;
        }
        return total <= k;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0, high = stations[n-1]-stations[0];
        double mid = 0;
        double ans = stations[n-1]-stations[0];
        while(high-low>=1e-6){
            mid = (low+high)/2;
            if(isPossible(stations,mid,k)){
                ans = mid;
                high = mid;
            }
            else low = mid;
        }
        return ans;
    }
};
