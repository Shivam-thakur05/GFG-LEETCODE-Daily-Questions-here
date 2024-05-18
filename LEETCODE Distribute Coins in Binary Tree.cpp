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
    int dfs(TreeNode* &root,int &moves){
        if(root == NULL) return 0;


       int leftP = dfs(root->left,moves);
       int rightP = dfs(root->right,moves);

        moves += abs(leftP) + abs(rightP);
            return (leftP+rightP+root->val)-1;

        return moves;
    }

    int distributeCoins(TreeNode* root) {
        int count = 0;
        dfs(root,count);

        return count;
    }
};
