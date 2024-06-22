class Solution {
public:
    long long ExtractNumber(string sentence) {
        long long ans = -1;
        
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] >= '0' && sentence[i] <= '9'){
                string temp = "";
                int j = i;
                while(sentence[j] >= '0' && sentence[j] <= '9'){
                   temp.push_back(sentence[j]);
                   j++;
                }
                for(int i = 0; i < temp.length(); i++){
                    if(temp[i] == '9') {
                        temp = '0';
                        break;
                    }
                }
                // After collecting digits, convert temp to long long
                if (!temp.empty()) {
                    long long flag = stoll(temp); // Use stoll for converting to long long
                    ans = max(ans, flag);
                }
                i = j - 1; // Move i to the last digit processed (loopp khtm hone ke bdd j ki value jaha tk jyegi whi se i ko start krnge)
            }
        }
        if(ans == 0) return -1;
        else return ans;
    }
};
