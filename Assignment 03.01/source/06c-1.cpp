#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next = nullptr;
};

void ThemVaoLinkedList(Node *&head, int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void HienThiThongTinLinkedList(Node *head) {
    Node *tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

void ThemVaoLinkedListCoThuTu(Node *&head, int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= x) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *tmp = head;
        while (tmp->next != nullptr && tmp->next->data < x) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

int main() {
    Node *head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ThemVaoLinkedList(head, x);
    }

    HienThiThongTinLinkedList(head);
    cout << "\n";

    int k;
    cout << "Enter a number to insert: ";
    cin >> k;
    ThemVaoLinkedListCoThuTu(head, k);
    HienThiThongTinLinkedList(head);
}