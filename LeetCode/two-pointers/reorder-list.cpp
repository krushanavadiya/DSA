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
    void reorderList(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head->next;

        while(f!=nullptr && f->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }

        ListNode* prev=nullptr;
        ListNode* s1=s->next;
        s->next=nullptr;

        while(s1!=nullptr){
            ListNode* temp=s1->next;
            s1->next=prev;
            prev=s1;
            s1=temp;
        }

        ListNode* curr=head;

        while(prev!=nullptr){
            ListNode* temp1=curr->next;
            ListNode* temp2=prev->next;
            curr->next=prev;
            prev->next=temp1;
            curr=temp1;
            prev=temp2;
        }

    }
};