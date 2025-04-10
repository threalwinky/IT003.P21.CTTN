#include<random>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#include<chrono>

using namespace std;
const int cnt = 1000000;
double real_numbers[cnt + 1];

void heapify(int n, int i) {
    int largest = i; 
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && real_numbers[left] > real_numbers[largest])
        largest = left;

    if (right <= n && real_numbers[right] > real_numbers[largest])
        largest = right;

    if (largest != i) {
        swap(real_numbers[i], real_numbers[largest]);
        heapify(n, largest);
    }
}

void heap_sort(int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify(n, i);

    for (int i = n; i >= 2; i--) {
        swap(real_numbers[1], real_numbers[i]);
        heapify(i - 1, 1);
    }
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    for (int index = 1; index <= cnt; index++) {
        cin >> real_numbers[index];
    }
    auto start_time = chrono::steady_clock::now();
    heap_sort(cnt);
    auto end_time = chrono::steady_clock::now();
    auto result = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    
    cout << result.count();
    return 0;
}