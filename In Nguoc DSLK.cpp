#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};

void insert_node(SinglyLinkedList *l, int x){
SinglyLinkedListNode* p = new SinglyLinkedListNode(x);
if(l->head == NULL){
    l->head = p;
}
else{
    l->tail->next = p;
}
l->tail = p;
}

void reverseLinkedList(SinglyLinkedList* l) {
    SinglyLinkedListNode* p = NULL;
    SinglyLinkedListNode* current = l->head;
    SinglyLinkedListNode* Next = NULL;

    while (current!= NULL) {
        Next = current->next;
        current->next = p;
        p = current;
        current = Next;
    }

    l->head = p;
}

void printLinkedList(SinglyLinkedList* l){
SinglyLinkedListNode* p;
p = l->head;
while(p!=NULL){
    cout<<p->data<<" ";
     p = p->next;
}
}
//###INSERT CODE HERE -

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
