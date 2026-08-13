/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(null  ptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x) , next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans= new ListNode();
        ListNode* head=ans;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                head->next= list1;
                head=head->next;
                list1=list1->next;
            }
            else{
                head->next=list2;
                head=head->next;
                list2=list2->next;
            }
        }

        if(list1==nullptr){
            head->next=list2;
        }
        else{
            head->next=list1;
        }

        return ans->next;
    }
};