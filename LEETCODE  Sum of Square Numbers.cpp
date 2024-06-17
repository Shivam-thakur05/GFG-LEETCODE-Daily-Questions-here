class Solution {
public:
    typedef long long ll;
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        ll start = 0;
        ll end = (ll)sqrt(c); // set end to the square root of c
        while(start <= end){
            ll sum = start * start + end * end;
            if(sum == c) return true;
            else if(sum < c) start++;
            else end--;
        }
        return false;
    }
};
