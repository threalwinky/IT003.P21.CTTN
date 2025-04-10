
#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

struct SinglyLinkedList {
	SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
		this->head = nullptr;
        this->tail = nullptr;
    }

	void insert_node(int node_data);
};

void SinglyLinkedList::insert_node(int node_data)
{
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}

		this->tail = node;
}



void print_singly_linked_list(SinglyLinkedListNode* node,char sep=' ') {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << '\n';
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2){

    SinglyLinkedListNode* curNode = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* headNode = curNode;
    SinglyLinkedListNode* tmp1Node = head_list1;
    SinglyLinkedListNode* tmp2Node = head_list2;
    while (tmp1Node != NULL && tmp2Node != NULL){
        SinglyLinkedListNode* newInsertNode = new SinglyLinkedListNode(0);
        if (tmp1Node->data < tmp2Node->data){
            newInsertNode->data = tmp1Node->data;
            tmp1Node = tmp1Node->next;
        }
        else{
            newInsertNode->data = tmp2Node->data;
            
            tmp2Node = tmp2Node->next;
        }
        curNode->next = newInsertNode;
        curNode = curNode->next;
    }
    while (tmp1Node != NULL){
        SinglyLinkedListNode* newInsertNode = new SinglyLinkedListNode(0);
        newInsertNode->data = tmp1Node->data;
        curNode->next = newInsertNode;
        curNode = curNode->next;
        tmp1Node = tmp1Node->next;
    }
    while (tmp2Node != NULL){
        SinglyLinkedListNode* newInsertNode = new SinglyLinkedListNode(0);
        newInsertNode->data = tmp2Node->data;
        curNode->next = newInsertNode;
        curNode = curNode->next;
        tmp2Node = tmp2Node->next;
    }
    curNode->next = NULL;
    headNode = headNode->next;
    return headNode;
}




int main (){
    cin.tie(0); std::ios::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    int tests;
    cin >> tests;
    
    
    
    
    for (int t = 0; t < tests; t++){
		int llist1_num, llist2_num;
		cin >> llist1_num >> llist2_num;
		
		SinglyLinkedList* llist1 = new SinglyLinkedList();
		
		
		for (int i = 0; i < llist1_num; i++){
			int llist1_item;
			cin >> llist1_item;
			
			llist1->insert_node(llist1_item);
		}
		
		SinglyLinkedList* llist2 = new SinglyLinkedList();

		
		for (int i = 0; i < llist2_num; i++){
			int llist2_item;
			cin >> llist2_item;
			
			llist2->insert_node(llist2_item);
		}
		
		SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
		
		print_singly_linked_list(llist3);
		
		free_singly_linked_list(llist3);
		
		
	}
}
