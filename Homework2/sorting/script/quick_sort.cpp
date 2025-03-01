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

void quick_sort(int left, int right) {
    double pivot = real_numbers[(left + right) >> 1];
    int i = left, j = right;
    while (i < j) {
        while (real_numbers[i] < pivot) {
            i++;
        }
        while (real_numbers[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(real_numbers[i++], real_numbers[j--]);
        }
    }
    if (i < right) {
        quick_sort(i, right);
    }
    if (left < j) {
        quick_sort(left, j);
    }
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    for (int index = 1; index <= cnt; index++) {
        cin >> real_numbers[index];
    }
    auto start_time = chrono::steady_clock::now();
    quick_sort(1, cnt);
    auto end_time = chrono::steady_clock::now();
    auto result = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    
    cout << result.count();
    return 0;
}