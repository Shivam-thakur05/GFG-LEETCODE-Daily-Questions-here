class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
   string smallestWindow (string s, string p)
    {
        int count1 = 0, count2 = 0, len = INT_MAX;
        int start = -1, end = -1, j = 0;
        int n = p.length();
        int m = s.length();
        if(n > m) return "-1";
        
        vector<int>forS(26,0);
        vector<int>forP(26,0);
        
        for(int i = 0; i < p.length(); i++){
            forP[p[i] - 'a']++;
            if(forP[p[i] - 'a'] == 1) count1++;
        }
        for(int i = 0; i < s.length(); i++){
            forS[s[i] - 'a']++;
            if(forS[s[i] - 'a'] == forP[s[i] - 'a']) count2++;
            if(count1 == count2){
                while(forS[s[j] - 'a'] > forP[s[j] - 'a'])  forS[s[j++]-'a']--;
                
                if(len > (i-j+1)) {
                    start = j;
                    end = i;
                    len = i-j+1;
                }
            }
        }
        if(start == -1) return "-1";
        return s.substr(start,len);
        
    }
};
