class Solution {
  public:
    string oddEven(string s) {
        int even = 0,odd = 0;
        unordered_map<char,int>mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        
        for(auto it:mp){
           char character = it.first;
            int freq = it.second;
            int pos = character - 'a' + 1; 
            
            if (pos % 2 == 0 && freq % 2 == 0) { 
                even++;
            }
            if (pos % 2 != 0 && freq% 2 != 0) {
                odd++;
            }
        }
        if ((even + odd) % 2 == 0) return "EVEN";
        else return "ODD";  
    }
};
