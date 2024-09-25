class Solution {
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        // Find the size of the linked list
        Node* curr = head;
        int size = 0;
        while (curr != nullptr) {
            curr = curr->next;
            size++;
        }

        // Find the start of the second half
        curr = head;
        Node* nextHalf = head;
        int i = size / 2;
        while (i > 0) {
            nextHalf = nextHalf->next;
            i--;
        }

        // Reverse the second half of the list
        Node* prev = nullptr;
        Node* temp = nextHalf;
        while (temp != nullptr) {
            Node* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        nextHalf = prev;

        // Compare the first half and the reversed second half
        curr = head;
        while (nextHalf != nullptr) {
            if (curr->data != nextHalf->data) return false;
            curr = curr->next;
            nextHalf = nextHalf->next;
        }

        return true;
    }
};
