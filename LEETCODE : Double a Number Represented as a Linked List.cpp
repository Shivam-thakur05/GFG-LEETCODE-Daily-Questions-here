//  first approach
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prevptr = NULL;
        ListNode* nextptr = NULL;

        while(curr!=NULL){
            nextptr = curr->next;
            curr->next = prevptr;

            prevptr = curr;
            curr = nextptr;
        }
        return prevptr;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        ListNode* prev = NULL;

        int digit = 0;
        int carry = 0;

        while(curr!=NULL){
            int newVal = 2*curr->val + carry;
            digit = newVal%10;
            curr->val = digit;

            carry = newVal/10;

            prev = curr;
            curr = curr->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }

        return reverse(head);
    }   
};

//  second approach
class Solution {
public:
    int solve(ListNode* head){
        if(head == NULL){
            return 0;
        }
        int carry = solve(head->next);
        int newVal = head->val*2+carry;
        head->val = newVal%10;

        return newVal/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int LastCarry = solve(head);
        if(LastCarry){
            ListNode* newHead = new ListNode(LastCarry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};
