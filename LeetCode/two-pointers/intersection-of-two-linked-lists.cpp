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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1=0;
        ListNode* curr=headA;
        while(curr!=nullptr){
            curr=curr->next;
            s1++;
        }

        int s2=0;
        ListNode* curr2=headB;
        while(curr2!=nullptr){
            curr2=curr2->next;
            s2++;
        }

        int diff=abs(s1-s2);

        curr=headA;
        curr2=headB;

        if(s1>s2){
            while(diff!=0){
                curr=curr->next;
                diff--;
            }
        }
        else if(s1<s2){
            while(diff!=0){
                curr2=curr2->next;
                diff--;
            }
        }
        
        while(curr!=curr2){
            curr=curr->next;
            curr2=curr2->next;
        }

        return curr;
    }
};