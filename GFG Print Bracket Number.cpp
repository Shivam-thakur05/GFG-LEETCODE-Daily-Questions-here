class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int>ans;
        int open = 0;
        int close;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '('){
                open++;
                ans.push_back(open);
                close = open;
            }
            else if(str[i] == ')'){
                ans.push_back(close);
                close--;
            }
        }
        return ans;
    }
};
