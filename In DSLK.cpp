/*
In danh sách liên kết đơn
Cho một danh sách liên kết đơn, hãy cài đặt hàm printLinkedList để in hãy in phần data của mỗi nút, mỗi phần tử trên một dòng riêng biệt. 
Chú ý hàm printLinkedList thuộc class SinglyLinkedList có thuộc tính head là con trỏ trỏ đến nút đầu của danh sách liên kết.
*/

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
//###INSERT CODE HERE -
SinglyLinkedListNode* p;
            p = head;
            while (p != NULL){
                cout<<p->data<<endl;
                p = p->next;
            }
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    llist->printLinkedList();
    free_singly_linked_list(llist->head);
	
    return 0;
}
