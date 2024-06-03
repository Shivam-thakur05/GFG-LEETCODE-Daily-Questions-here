class Solution {
public:
    int appendCharacters(string s, string t) {
        int count = 0;
        int i = 0;
        int j = 0;
        while(i < s.length()){
            if(s[i] == t[j]){
                i++;
                j++;
                count++;
            }
            else{
                i++;
            }
        }
        cout<<count<<" "<<t.length();
        return t.length()-count;
    }
};
