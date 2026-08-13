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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* s=head;
        ListNode* f=head->next;

        while(f!=nullptr && f->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }

        ListNode* mid= s->next;
        s->next=nullptr;

        ListNode* l=sortList(head);
        ListNode* r=sortList(mid);

        return merge(l,r);
    }

    ListNode* merge(ListNode* l, ListNode* r){
        ListNode* ans= new ListNode(0);

        ListNode* temp=ans;

        while(l!=nullptr && r!=nullptr){
            if(l->val<r->val){
                temp->next=l;
                l=l->next;
            }
            else{
                temp->next=r;
                r=r->next;
            }
            temp=temp->next;
        }

        if(l!=nullptr){
            temp->next=l;
        }
        else{
            temp->next=r;
        }

        return ans->next;
    }
};