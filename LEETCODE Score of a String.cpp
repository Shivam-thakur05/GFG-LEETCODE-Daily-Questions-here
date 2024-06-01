class Solution {
public:
    int scoreOfString(string s) {
        int a,b;
        int sum = 0;
        int i = 0;
        while(i < s.length()-1){
            a = s[i];
            b = s[++i];
            sum += abs(a - b);

            a = b;
        }
        return sum;
    }
};
