/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool solve(Node *root, int target, int sum){
        if (!root) return false;
        
        sum += root->data;
        
        // Check if the current node is a leaf and the sum equals the target
        if (!root->left && !root->right) {
            return sum == target;
        }
        
        // Recursively check the left and right subtrees
        return solve(root->left, target, sum) || solve(root->right, target, sum);
    }
    
    bool hasPathSum(Node *root, int target) {
        int sum = 0;
        return solve(root, target, sum);
    }
};
