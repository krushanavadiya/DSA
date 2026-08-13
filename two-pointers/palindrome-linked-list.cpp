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
    bool isPalindrome(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head->next;

        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }

        ListNode* rev=nullptr;
        ListNode* curr=s->next;

        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=rev;
            rev=curr;
            curr=temp;
        }
        
        s=head;
        while( rev!=nullptr){
            if(s->val!=rev->val){
                return false;
            }else{
                s=s->next;
                rev=rev->next;
            } 
        }

        return true;
    }
};