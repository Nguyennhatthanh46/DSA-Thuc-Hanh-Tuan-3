/*
Thêm một phần tử vào đầu danh sách liên kết đơn Cho một danh sách liên kết đơn, 
hãy cài đặt hàm SinglyLinkedListNode* insertNodeAtHead(int )  để thêm một nút có thuộc tính data có giá trị _data vào đầu danh sách liên kết đơn. 
Chú ý hàm  insertNodeAtHead(int ) thuộc lớp SinglyLinkedList có thuộc tính head là con trỏ trỏ đến nút đầu của danh sách liên kết.
*/

#include <iostream>
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

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }
            this->tail = node;
        }
        void printLinkedList() {
            SinglyLinkedListNode* p;
            p = head;
            while (p != NULL){
                cout<<p->data<<endl;
                p = p->next;
            }
        }


	 SinglyLinkedListNode* insertNodeAtHead(int _data) {
//###INSERT CODE HERE -
SinglyLinkedListNode* node = new SinglyLinkedListNode(_data);
if(head == NULL){
    head = node;
    tail = head;
}else {
node->next = head;
head = node;
}
return node;
	 }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}



int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist->insert_node(llist_item);
    }

    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist->insertNodeAtHead(llist_item);
    }

    llist->printLinkedList();
    free_singly_linked_list(llist->head);

    return 0;
}
