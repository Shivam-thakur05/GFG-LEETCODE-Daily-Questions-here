/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root,vector<int>&inOrderVal){
        if(root == NULL) return;

        inOrder(root->left,inOrderVal);
        inOrderVal.push_back(root->val);
        inOrder(root->right,inOrderVal);

    }
    TreeNode* solve(int s,int e, vector<int>&inOrderVal){
        if(s > e){
            return nullptr;
        }
        int mid = s + (e - s)/2;
        TreeNode* root = new TreeNode(inOrderVal[mid]);
        root->left = solve(s,mid-1,inOrderVal);
        root->right = solve(mid+1,e,inOrderVal);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inOrderVal;
        inOrder(root,inOrderVal);
        return solve(0,inOrderVal.size()-1,inOrderVal);
    }
};
