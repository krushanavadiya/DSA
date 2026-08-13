/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; */
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* ans=new Node(0);
        Node* temp=ans;

        Node* dummy=new Node(0);
        Node* t=dummy;

        Node* curr=head;

        while(curr!=nullptr){
            if(curr->data%2==0){
                
                temp->next=curr;
                temp=curr;
            }
            else{
                
                t->next=curr;
                t=curr;
            }
            curr=curr->next;
        }
