class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x == 1) return head->next;
        Node* temp = head;
        int count = 1;
        //make temp to deleting node
        while(count < x){
            temp = temp -> next;
            count++;
        }
        temp->prev->next = temp->next;
        if(temp->next != NULL) temp->next->prev = temp->prev;
        
        return head;
        
    }
};
