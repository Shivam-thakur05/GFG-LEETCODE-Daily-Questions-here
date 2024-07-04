class Solution {
  public:
    string solve(Node* root,vector<Node*>&ans,unordered_map<string,int>&mp){
        if(root == NULL) return "#";
        string temp = to_string(root->data)+' '+solve(root->left,ans,mp)+' '+solve(root->right,ans,mp);
        if(mp[temp] == 1) ans.push_back(root);
        mp[temp]++;
        return temp;
    }
    vector<Node*> printAllDups(Node* root) {
          vector<Node*>ans;
          unordered_map<string,int>mp;
          solve(root,ans,mp);
          return ans;
    }
};
