#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

void mer(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void merSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merSort(arr, l, m);
        merSort(arr, m + 1, r);
        mer(arr, l, m, r);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> check(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    merSort(arr, 0, n - 1);
    
    arr.push_back(-123456789);
    for (int i = 0; i < n; i++) {
        // cout << arr[i] << " ";
        if (arr[i] != arr[i + 1]) {
            check[i] = 1;
            cout << arr[i] << " ";
            k--;
            if (k == 0) break;
        }
    }
    // cout << "\n";
    for (int i = 0; i < n; i++) {
        if (check[i] != 1 && k > 0) {
            cout << arr[i] << " ";
            k--;
            if (k == 0) break;
        }
    }
    return 0;
}