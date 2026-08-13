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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum=0;
        ListNode* ans=new ListNode(0);
        unordered_map<int, ListNode*> fq;
        ListNode* curr=head;
        ans->next=curr;
        fq[0]=ans;
        while(curr!=nullptr){
            sum+=curr->val;

            if(fq.contains(sum)){
                ListNode* st=fq[sum];
                ListNode* temp2=st->next;
                int nSum=sum;
                while(temp2!=curr){
                    nSum+=temp2->val;
                    fq.erase(nSum);
                    temp2=temp2->next;
                }
                st->next=curr->next;
            }
            else{
                fq[sum]=curr;
            }
            curr=curr->next;
        }

        return ans->next;
    }
};