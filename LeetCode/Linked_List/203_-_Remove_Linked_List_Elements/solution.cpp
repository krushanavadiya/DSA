    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans=new ListNode(0);
        ans->next=head;
        ListNode* curr=head;
        ListNode* prev=ans;

        while(curr!=nullptr){
            if(curr->val==val){
                prev->next=curr->next;
                curr=curr->next;
            }

            else{
                prev=curr;
                curr=curr->next;
            }
        }

        return ans->next;
    }

