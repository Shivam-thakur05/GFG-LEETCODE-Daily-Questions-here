class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;

        // Choose the higher value between x and y to prioritize
        if (x > y) {
            for (char ch : s) {
                if (!st.empty() && st.top() == 'a' && ch == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(ch);
                }
            }

            string remaining;
            while (!st.empty()) {
                remaining.push_back(st.top());
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());

            for (char ch : remaining) {
                if (!st.empty() && st.top() == 'b' && ch == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(ch);
                }
            }
        } else {
            for (char ch : s) {
                if (!st.empty() && st.top() == 'b' && ch == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(ch);
                }
            }

            string remaining;
            while (!st.empty()) {
                remaining.push_back(st.top());
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());

            for (char ch : remaining) {
                if (!st.empty() && st.top() == 'a' && ch == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(ch);
                }
            }
        }

        return ans;
    }
};
