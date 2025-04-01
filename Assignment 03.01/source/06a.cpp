#include<iostream>
#include<algorithm>
using namespace std;
void InsertToArray(int *array, int n, int k){
    array = (int*)realloc(array, (n + 1) * sizeof(int));
    int i;
    for (i = n - 1; (i >= 0 && array[i] > k); i--){
        array[i + 1] = array[i];
    }
    array[i + 1] = k;
    cout << "New array: ";
    for (int j = 0; j <= n; j++){
        cout << array[j] << " ";
    }
}
int main(){
    int n; cin >> n;
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    sort(array, array + n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
    int k;
    cout << "Enter a number to insert: ";
    cin >> k;
    InsertToArray(array, n, k);
}