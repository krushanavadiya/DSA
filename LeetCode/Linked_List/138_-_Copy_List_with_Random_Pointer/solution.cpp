/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node* , Node*> newL;

        Node* curr=head;

        while(curr!=nullptr){
            newL[curr]=new Node(curr->val);
            curr=curr->next;
        }

        curr=head;
        while(curr){
            newL[curr]->next=newL[curr->next];
            newL[curr]->random=newL[curr->random];
            curr=curr->next;
        }

        return newL[head];
    }
};