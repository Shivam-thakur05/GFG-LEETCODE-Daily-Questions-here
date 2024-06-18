class Solution {
  public:
    int rectanglesInCircle(int r1) {
        int ans= 0;
        double r = (double)(r1);
        for(double i = 1.0;i<2.0*r;i++){
            double cal  = 2.0*sqrt(r*r - ((i/2.0)*(i/2.0)));
            int cal1 = floor(cal);
            // cout<<cal1<<" ";
            ans += cal1;
            
        }
        return ans;
    }
};
