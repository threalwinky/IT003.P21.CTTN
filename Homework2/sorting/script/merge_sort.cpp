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
double left_array[cnt], right_array[cnt];

void merge(int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    for (int i = 0; i < left_size; i++)
        left_array[i] = real_numbers[left + i];
    for (int j = 0; j < right_size; j++)
        right_array[j] = real_numbers[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            real_numbers[k] = left_array[i];
            i++;
        } else {
            real_numbers[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        real_numbers[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_size) {
        real_numbers[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main(int arvc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    double real_number;
    for (int index = 1; index <= cnt; index++) {
        cin >> real_numbers[index];
    }
    auto start_time = chrono::steady_clock::now();
    merge_sort(1, cnt);
    auto end_time = chrono::steady_clock::now();
    auto result = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    
    cout << result.count();
    return 0;
}
