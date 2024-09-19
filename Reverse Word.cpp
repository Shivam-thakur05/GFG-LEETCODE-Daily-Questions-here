//first approach

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        string ans = "";
        string word = "";
        for(int i = str.length()-1; i >= 0; i--){
            if(str[i] != '.') word = str[i]+word;
            else{
                ans = ans+word ;
                ans = ans+str[i];
                word = "";
            }
        }
        ans = ans+word;
        return ans;
    }
};


//second approach

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        vector<string> res; string temp = "", ans = "";
        for ( auto i : str ){
            if ( i == '.' ){
                res.push_back(temp);
                temp = ""; 
            } 
            else temp += i;
        } 
        res.push_back(temp);
        reverse(res.begin(),res.end());
        
        for ( int i = 0; i<res.size(); i++ ){
            if ( i == res.size()-1 ) ans += res[i];
            else ans += res[i] + ".";
        } 
    return ans;
    }
};

is this correct
