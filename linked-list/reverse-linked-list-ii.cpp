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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right) return head;

        ListNode* ans=new ListNode(0);
        ans->next=head;

        int s=0;
        ListNode* curr=ans;
        
        ListNode* l=nullptr;
        ListNode* r=nullptr;

        while(s<left-1){
            s++;
            curr=curr->next;
        }

        ListNode* st=curr;
        l=curr->next;

        while(s<right){
            s++;
            curr=curr->next;
        }

        r=curr;
        ListNode* end=curr->next;

        ListNode* prev=end;
        
        while(prev!=r){
            ListNode* temp=l->next;
            l->next=prev;
            prev=l;
            l=temp;
        }

        st->next=prev;

        return ans->next;
    }
};