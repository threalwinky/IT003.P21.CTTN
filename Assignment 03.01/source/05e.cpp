#include <iostream>
using namespace std;

struct SinhVienNode {
    char *data;
    SinhVienNode *prev, *next;
};

void ChuyenArraySangLinkedList(char **SinhVienArray, SinhVienNode *&head, int n) {
    head = NULL;
    SinhVienNode *tail = NULL;
    for (int i = 0; i < n; i++) {
        SinhVienNode *newNode = (SinhVienNode *)malloc(sizeof(SinhVienNode));
        newNode->data = SinhVienArray[i];
        if (!head) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        }
        tail = newNode;
    }
}

void ChuyenLinkedListSangArray(SinhVienNode *head, char **&SinhVienArray, int n) {
    SinhVienNode *current = head;
    for (int i = 0; i < n; i++, current = current->next)
        SinhVienArray[i] = current->data;
}

void HienThiThongTinLinkedList(SinhVienNode *head, int n) {
    SinhVienNode *current = head;
    for (int i = 0; i < n; i++, current = current->next)
        cout << current->data << " ";
}

int main() {
    int n; cin >> n;
    char **SinhVienArray = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        SinhVienArray[i] = (char *)malloc(1000);
        cin >> SinhVienArray[i];
    }
    SinhVienNode *head;
    ChuyenArraySangLinkedList(SinhVienArray, head, n);

    cout << "Linked List: ";
    HienThiThongTinLinkedList(head, n);
    cout << "\n";

    char **NewSinhVienArray = (char**)malloc(n * sizeof(char*));
    ChuyenLinkedListSangArray(head, NewSinhVienArray, n);

    cout << "New Array: ";
    for (int i = 0; i < n; i++) cout << NewSinhVienArray[i] << " ";

}