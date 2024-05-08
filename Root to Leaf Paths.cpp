class Solution {
  public:
   vector<vector<int>> res;
    void helper(Node* root , vector<int> &arr){
        if(root == NULL){
            return;
        }
        arr.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            
            res.push_back(arr);
            arr.pop_back();
            return;
        }
        
        helper(root->left , arr);
        helper(root->right , arr);
        arr.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> arr;
        helper(root , arr);
        return res;
    }
};
