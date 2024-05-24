class Solution {
public:
    void solve(int i,vector<int>& score, vector<string>& words,int currScore,
                vector<int>&freq,int &maxScore){
        
        maxScore = max(maxScore,currScore);
        if(i >= words.size()){
            return;
        }
        int j = 0;
        int tempScore = 0;
        vector<int>tempFreq = freq;
        while(j < words[i].length()){
            char ch = words[i][j];

            tempFreq[ch-'a']--;
            tempScore += score[ch-'a'];

            if(tempFreq[ch-'a'] < 0){
                break;
            }
            j++;
        }
        if(j == words[i].length()){
            solve(i+1,score,words,currScore+tempScore,tempFreq,maxScore);
        }
            solve(i+1,score,words,currScore,freq,maxScore);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        int maxScore = INT_MIN;
        for(char ch: letters) freq[ch-'a']++;

        solve(0,score,words,0,freq,maxScore);
        return maxScore;
    }
};
