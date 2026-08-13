/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* l0=new Node(0);
        Node* temp=l0;

        Node* l1=new Node(0);
        Node* t=l1;
        
        Node* l2=new Node(0);
        Node* u=l2;
        
        Node* curr=head;

        while(curr!=nullptr){
            if(curr->data==0){
                temp->next=curr;
                temp=curr;
            }
            
            else if(curr->data==1){
                t->next=curr;
                t=curr;
