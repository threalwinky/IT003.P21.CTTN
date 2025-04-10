
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




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void insert_node(SinglyLinkedList* llist, int node_data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(node_data);

    if (!llist->head) {
        llist->head = newNode;
    } else {
        llist->tail->next = newNode;
    }

    llist->tail = newNode;
}

void reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedList rev = SinglyLinkedList();
    SinglyLinkedListNode* current = llist->head;
    while (current != NULL) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(current->data);
        newNode->next = rev.head;
        rev.head = newNode;
        current = current->next;
    }
    llist->head = rev.head;
    llist->tail = rev.tail;
    SinglyLinkedListNode* currentTail = rev.head;
    while (currentTail->next != NULL) {
        currentTail = currentTail->next;
    }
}

void printLinkedList(SinglyLinkedList *list) {
    SinglyLinkedListNode* current = list->head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

 int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
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
