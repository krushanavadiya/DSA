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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;

        ListNode* dummy=new ListNode(0);
        ListNode* t=dummy;

        ListNode* curr=head;
        int i=1;
        while(curr!=nullptr){
            if(i%2!=0){
                temp->next=curr;
                temp=curr;
            }
            else{
                
                t->next=curr;
                t=curr;
            }
            curr=curr->next;
            i++;
        }
        
        t->next=nullptr;
        temp->next=dummy->next;

        return ans->next;
    }
};