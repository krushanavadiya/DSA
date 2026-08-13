/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;

        ListNode* dummy=new ListNode(0);
        ListNode* t=dummy;

        ListNode* curr=head;

        while(curr!=nullptr){
            if(curr->val<x){
                // ListNode* n=new ListNode(curr->val);
                temp->next=curr;
                temp=curr;
            }
            else{
                // ListNode* n=new ListNode(curr->val);
                t->next=curr;
                t=curr;
            }
            curr=curr->next;
        }
        t->next=nullptr;
        temp->next=dummy->next;

        return ans->next;
    }
};

