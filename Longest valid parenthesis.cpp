class Solution {
  public:
    int maxLength(string& str) {
        int opening = 0,closing = 0;
        int maxi = 0;
        
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(') opening++;
            else closing++;
            
            if(closing > opening) {
                opening = closing = 0;
            }
            if(closing == opening){
                maxi = max(maxi,opening*2);
            }
        }
        
        opening = closing = 0;
        
        for(int i = str.length()-1; i >= 0; i--){
            if(str[i] == ')') closing++;
            else opening++;
            
            if(closing < opening) {
                opening = closing = 0;
            }
            if(closing == opening){
                maxi = max(maxi,opening*2);
            }
        }
        return maxi;
    }
};
