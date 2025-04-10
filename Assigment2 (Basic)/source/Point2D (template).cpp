#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

struct A {
    int x, y;
};

bool cmp(A a, A b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x < b.x;
}

void merge(vector<A> &v, int l, int m, int r) {
    vector<A> left(v.begin() + l, v.begin() + m + 1);
    vector<A> right(v.begin() + m + 1, v.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (cmp(left[i], right[j])) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
        }
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

void mergeSort(vector<A> &v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    
    vector<A> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    mergeSort(v, 0, n - 1);
    
    for (auto it : v) {
        cout << it.x << " " << it.y << "\n";
    }
}