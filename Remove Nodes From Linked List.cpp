class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* curr = head;

        while(curr!=NULL){
            st.push(curr);
            curr = curr->next;
        }
        curr = st.top();
        st.pop();
        int maxValue = curr->val;

        ListNode* resultHead = new ListNode(curr->val);

        while(!st.empty()){
            curr = st.top();
            st.pop();
            if(curr->val < maxValue){
                continue;   //skip this node
            }
            else{
                ListNode* newNode = new ListNode(curr->val);
                newNode->next = resultHead;
                resultHead = newNode;
                maxValue = curr->val;
            }
        }
        return resultHead;
    }
};
