#include <iostream>
using namespace std;
struct SinhVienNode{
    char *data;
    SinhVienNode *next;
};
void ChuyenArraySangLinkedList(char **SinhVienArray, SinhVienNode *&SinhVienLinkedList, int n){
    SinhVienLinkedList = NULL;
    for (int i = n - 1; i >= 0; i--){
        SinhVienNode *newNode = (SinhVienNode*)malloc(sizeof(SinhVienNode));
        newNode->data = SinhVienArray[i];
        newNode->next = SinhVienLinkedList;
        SinhVienLinkedList = newNode;
    }
}
void ChuyenLinkedListSangArray(SinhVienNode *SinhVienLinkedList, char **&SinhVienArray, int n){
    SinhVienNode *current = SinhVienLinkedList;
    for (int i = 0; i < n; i++){
        SinhVienArray[i] = current->data;
        current = current->next;
    }
}
void HienThiThongTinLinkedList(SinhVienNode *SinhVienLinkedList){
    SinhVienNode *current = SinhVienLinkedList;
    while (current){
        cout << current->data << " ";
        current = current->next;
    }
}
int main(){
    int n;
    cin >> n;
    char **SinhVienArray = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++){
        SinhVienArray[i] = (char *)malloc(1000);
        cin >> SinhVienArray[i];
    }
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << SinhVienArray[i] << " ";
    cout << "\n";
    SinhVienNode *SinhVienLinkedList;
    ChuyenArraySangLinkedList(SinhVienArray, SinhVienLinkedList, n);
    cout << "Linked List: ";
    HienThiThongTinLinkedList(SinhVienLinkedList);
    cout << "\n";
    char **NewSinhVienArray = (char **)malloc(n * sizeof(char *));
    ChuyenLinkedListSangArray(SinhVienLinkedList, NewSinhVienArray, n);
    cout << "New Array: ";
    for (int i = 0; i < n; i++) cout << NewSinhVienArray[i] << " ";
}