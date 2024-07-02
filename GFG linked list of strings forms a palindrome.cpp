/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        string ans = "";
        while(head != NULL){
           // char ch = head->data;
            ans += head->data;
            head = head->next;
        }
        int start = 0;
        int end = ans.length()-1;
        
        while(start <= end){
            if(ans[start] != ans[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};
