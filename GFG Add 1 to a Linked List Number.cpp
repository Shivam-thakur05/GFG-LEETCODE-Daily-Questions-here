class Solution {
  public:
  Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move pointers one position ahead
            curr = next;
        }
        return prev;
    }
   Node* addOne(Node* head) {
        // Step 1: Reverse the linked list.
        head = reverseList(head);
        
        // Step 2: Add one to the reversed list.
        Node* curr = head;
        int carry = 1;
        Node* prev = NULL;
        
        while (curr != NULL) {
            int sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;
            prev = curr;
            curr = curr->next;
        }
        
        // If carry is still left, add a new node.
        if (carry > 0) {
            prev->next = new Node(carry);
        }
        
        // Step 3: Reverse the list back to its original order.
        head = reverseList(head);
        
        return head;
    }
