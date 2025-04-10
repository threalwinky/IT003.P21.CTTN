#include <iostream>
using namespace std;

struct SinhVienNode {
    char *data;
    SinhVienNode *prev, *next;
};

void ChuyenArraySangLinkedList(char **SinhVienArray, SinhVienNode *&head, SinhVienNode *&tail, int n) {
    head = tail = NULL;
    for (int i = 0; i < n; i++) {
        SinhVienNode *newNode = (SinhVienNode *)malloc(sizeof(SinhVienNode));
        newNode->data = SinhVienArray[i];
        newNode->next = NULL;
        newNode->prev = tail;
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
}

void ChuyenLinkedListSangArray(SinhVienNode *head, char **&SinhVienArray, int n) {
    SinhVienNode *current = head;
    for (int i = 0; i < n; i++, current = current->next)
        SinhVienArray[i] = current->data;
}

void HienThiThongTinLinkedList(SinhVienNode *head) {
    for (SinhVienNode *current = head; current; current = current->next)
        cout << current->data << " ";
}

int main() {
    int n; cin >> n;
    char **SinhVienArray = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        SinhVienArray[i] = (char *)malloc(1000);
        cin >> SinhVienArray[i];
    }
    SinhVienNode *head, *tail;
    ChuyenArraySangLinkedList(SinhVienArray, head, tail, n);

    cout << "Linked List: ";
    HienThiThongTinLinkedList(head);
    cout << "\n";

    char **NewSinhVienArray = (char**)malloc(n * sizeof(char*));
    ChuyenLinkedListSangArray(head, NewSinhVienArray, n);

    cout << "New Array: ";
    for (int i = 0; i < n; i++) cout << NewSinhVienArray[i] << " ";

}