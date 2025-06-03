#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

struct HeaderNode {
    Node* lastNode;
    Node* next;
};

void HienThiThongTinLinkedList(HeaderNode* header) {
    Node* tmp = header->next;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

void ThemVaoLinkedListCoThuTu(HeaderNode* header, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    Node* tmp = header->next;

    if (header->next == nullptr || header->next->data >= x) {
        newNode->next = header->next;
        header->next = newNode;
        if (header->next->next == nullptr) {
            header->lastNode = newNode;
        }
    } else {
        while (tmp->next != nullptr && tmp->next->data < x) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;

        if (newNode->next == nullptr) {
            header->lastNode = newNode;
        }
    }
}

int main() {
    HeaderNode* header = new HeaderNode;
    header->lastNode = nullptr;
    header->next = nullptr;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ThemVaoLinkedListCoThuTu(header, x);
    }

    HienThiThongTinLinkedList(header);
    cout << "\n";

    int k;
    cout << "Enter a number to insert: ";
    cin >> k;
    ThemVaoLinkedListCoThuTu(header, k);

    HienThiThongTinLinkedList(header);
    cout << "Address of the last node: " << header->lastNode << "\n";
}
