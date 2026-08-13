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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)  return head;
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;

        ListNode* tail=head;
        int size=1;
        while(tail->next!=nullptr){
            tail=tail->next;
            size++;
        }

        tail->next=head;

        ListNode* curr=head;
        k=k%size; //if k>size 
        int t=size-k;
        while(t>0){
            curr=curr->next;
            t--;
        }

        int i=0;
        while(i<size){
            temp->next=curr;
            temp=curr;
            curr=curr->next;
            i++;
        }

        temp->next=nullptr; //break the cycle
        return ans->next;
    }
};