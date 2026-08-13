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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr && curr->next!=nullptr){
            if(curr->val!=curr->next->val){
                if(prev==nullptr){
                    head=curr;
                    prev=curr;
                }
                else{
                    prev->next=curr;
                    prev=curr;
                }
                curr=curr->next;
            }
            else{
                while(curr->next!=nullptr && curr->val==curr->next->val){
                    curr=curr->next;
                }
                curr=curr->next;
                if(prev==nullptr){
                    head=curr;
                }
                else{
                    prev->next=curr;
                }
            }
        }

        return head;
    }
};