class Solution {
public:
    int countNumberswith4(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num > 0) {
                int rem = num % 10;
                if (rem == 4) {
                    count++;
                    break;  // We can break early since we only need to count each number once
                }
                num = num / 10;
            }
        }
        return count;
    }
};
