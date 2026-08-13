/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;

        while(f!=nullptr && f->next!=nullptr){
            s=s->next;
            f=f->next->next;
            if(s==f){
                break;
            }
        }

        if(f==nullptr || f->next==nullptr) return NULL;

        while(head!=s){
            head=head->next;
            s=s->next;
        }

        return head;
    }
};