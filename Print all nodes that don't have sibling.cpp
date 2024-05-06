void solve(Node* node, vector<int>&ans){
    //base case
    if(node == NULL) return;
       
       if(node->left && node->right == NULL){
           ans.push_back(node->left->data);
       }
       if(node->left==NULL && node->right){
           ans.push_back(node->right->data);
       }
    solve(node->left,ans);
    solve(node->right,ans);    
}

vector<int> noSibling(Node* node)
{
   vector<int>ans;
   solve(node,ans);
   if(ans.size() == 0){
       ans.push_back(-1);
   }
   sort(ans.begin(),ans.end());
   return ans;
   
}
