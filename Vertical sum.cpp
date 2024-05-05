class Solution{
  public:
    map<int,int>mp;
    void solve(Node* root,int dist){
        mp[dist] += root->data;
        
        if(root->left) solve(root->left,dist-1);
        if(root->right) solve(root->right,dist+1);
    }
    vector <int> verticalSum(Node *root) {
     solve(root,0);
     vector<int>ans;
     
     //store element in vector
     for(auto x : mp){
         ans.push_back(x.second);
     }
     return ans;
    }
};
