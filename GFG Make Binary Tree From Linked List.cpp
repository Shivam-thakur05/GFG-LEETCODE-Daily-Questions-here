class Solution {
  public:
    void convert(Node *head, TreeNode *&root) {
    queue<TreeNode *> q;
    Node *temp = head;

    TreeNode *curr = (TreeNode *)malloc(sizeof(TreeNode));
    curr->data = head->data;
    curr->left = NULL;
    curr->right = NULL;
    root = curr;
    q.push(curr);;
    while(q.size()) {
         int len = q.size();
         for(int i = 0 ; i < len; i++){
            TreeNode *temp1 = q.front();
            q.pop();
            //cout << temp1->data << " ";
            temp = temp->next;
            if(temp){
                TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
                new_node->data  = temp->data;
                new_node->left  = NULL;
                new_node->right = NULL;
                temp1->left = new_node;
                q.push(temp1->left);
            }
            else{
                temp1->left = NULL;
                //temp1->right = NULL;
                return;
            }
            temp = temp->next;
            if(temp){
                TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
                new_node->data  = temp->data;
                new_node->left  = NULL;
                new_node->right = NULL;
                temp1->right = new_node;
                q.push(temp1->right);
            }
            else
            {
                //temp1->left = NULL;
                temp1->right = NULL;
                return;
            }
            
         }
    }
    }
};
