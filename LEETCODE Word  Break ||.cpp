class Solution {
public:
    void solve(int i,string &currSentence,string s,vector<string> &ans,unordered_set<string> &st){
        if(i >= s.length()){
            ans.push_back(currSentence);
            return;
        }
        for(int j = i; j < s.length(); j++){
            string tempWord = s.substr(i,j-i+1);
            if(st.count(tempWord)){    //valid word
                string tempSentence = currSentence;
                    if(!currSentence.empty()){
                        currSentence += " ";
                    }
                currSentence += tempWord;   //take tempWord
                solve(j+1,currSentence,s,ans,st);      //Explore
                currSentence = tempSentence;    //remove tempword
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_set<string> st;
        for(string& word : wordDict){
            st.insert(word);
        }
        string currSentence = "";

        solve(0,currSentence,s,ans,st);
        return ans;
    }
};
