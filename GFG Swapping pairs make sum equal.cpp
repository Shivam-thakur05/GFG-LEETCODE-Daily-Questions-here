class Solution {
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++) 
            sum1+=a[i];
        for(int i=0;i<m;i++) 
            sum2 += b[i];
        int val = sum1-sum2;
        if (val%2!= 0) return -1;
        int target = val/2;
        set<int>setA(a,a+n);
        for(int i=0;i<m;i++) {
            int currValue=b[i]+target;
            if(setA.find(currValue)!=setA.end()) {
                return 1; 
            }
        }

    return -1;
   }
};
