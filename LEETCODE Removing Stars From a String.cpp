//approach 1 
//brute force space complexity O(n)
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char>st;
        for(int i = 0; i < n; i++){
            if(s[i] != '*') st.push(s[i]);
            else{
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

//approach 2
//Optimal solution
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '*') ans.push_back(s[i]);
            else{
                ans.pop_back();
            }
        }
        return ans;
    }
};
