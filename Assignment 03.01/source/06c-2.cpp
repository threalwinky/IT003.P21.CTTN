#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next = nullptr;
};

void ThemVaoLinkedList(Node *&head, Node *&tail, int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void HienThiThongTinLinkedList(Node *head) {
    Node *tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

void ThemVaoLinkedListCoThuTu(Node *&head, Node *&tail, int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    Node *tmp = head;

    if (head == nullptr || head->data >= x) {
        newNode->next = head;
        head = newNode;
        if (head->next == nullptr) {
            tail = head;
        }
    } else {
        while (tmp->next != nullptr && tmp->next->data < x) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ThemVaoLinkedList(head, tail, x);
    }

    HienThiThongTinLinkedList(head);
    cout << "\n";

    int k;
    cout << "Enter a number to insert: ";
    cin >> k;
    ThemVaoLinkedListCoThuTu(head, tail, k);
    HienThiThongTinLinkedList(head);
}
