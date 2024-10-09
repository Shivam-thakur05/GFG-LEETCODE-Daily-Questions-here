//using stack T.C. - O(N), S.C. - O(N)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char>st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }
};


//O(1) Space Complexity

class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0;
        int closing = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                opening++;
            }
            else{
                if(opening > 0) opening--;
                else closing++;
            }
        }

        return (closing+opening);
    }
};
