class List{
public:
    int val;
    List* next;
    List(int val){
        this->val=val;
        this->next=NULL;
    }
};

class MyLinkedList {
public:
    List* head;
    List* tail;
    int size;

    MyLinkedList() {
        head=tail=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        else if(index==0) return head->val;
        else if(index==size-1) return tail->val;
        else{
            List* temp=head;
            int i=0;
            while(i<index){
                temp=temp->next;
                i++;
            }
            return temp->val;
        }
    }
    
    void addAtHead(int val) {
        List *temp = new List(val);
        if(size==0) head=tail=temp;
        else {
            temp->next=head;
            head=temp;
        }
        size++;
    }
    
    void addAtTail(int val) {
        List *temp= new List(val);
        if(size==0) {
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        List* temp=new List(val);
        if(index==0) {
           addAtHead(val);
           return;

        }
        else if(index==size){
            addAtTail(val);
            return;
        }
        else{
            List* dup=head;
            int i=1;
            while(i<index){
                dup=dup->next;
                i++;
            }
            temp->next=dup->next;
            dup->next=temp;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;

        else if(index==0){
            head=head->next;
            size--;
            if(size==0) tail=NULL;
            return;
        }

        else if(index==size-1){
            List* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }

        else {
            List* temp=head;
            int i=1;
            while(i<index){
                temp=temp->next;
                i++;
            }
            temp->next=temp->next->next;
            size--;
        }

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */