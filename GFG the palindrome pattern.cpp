
class Solution {
  public:
    string pattern(vector<vector<int>> &arr) {
        int row = arr.size();
        int col = arr[0].size();
        string ans = ""
        //first check palindrome for row 
        for(int i = 0; i < arr.size(); i++){
            bool isPalindrome = true;
            for(int j = 0; j < arr[0].size()/2; j++){
                 if(arr[i][j]!=arr[i][row-1-j]){
                     isPalindrome = false;
                     break;
                 } 
            }
           if(isPalindrome) {
               return to_string(i) + " R";
           }
        }
        //again check palindrome for col if not find any palindrome in row 
        for(int i = 0; i < arr.size(); i++){
            bool isPalindrome = true;
            for(int j = 0; j < arr[0].size()/2; j++){
                 if(arr[j][i]!=arr[row-1-j][i]){
                     isPalindrome = false;
                     break;
                 } 
            }
           if(isPalindrome) {
               return to_string(i) + " C";
           }
        }
        return "-1";    
    }
};
