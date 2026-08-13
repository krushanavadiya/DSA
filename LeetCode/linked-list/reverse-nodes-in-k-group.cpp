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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;

        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* curr=head;
        ListNode* prev=nullptr;

        while(curr!=nullptr){
            ListNode* st=curr;

            for(int i=0; i<k-1; i++){
                curr=curr->next;
                if(curr==nullptr) break;
            }

            if(curr==nullptr){
                if(prev!=nullptr){
                    prev->next=st;
                }
                break;
            }

            ListNode* next=curr->next;
            curr->next=nullptr;
            ListNode* newSt=reverse(st);

            if(head==st) head=newSt;
            else prev->next=newSt;

            prev=st;
            curr=next;
        }

        return head;
    }
};