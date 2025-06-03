#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

void merge(vector<string> &a, int l, int m, int r) {
    vector<string> left(a.begin() + l, a.begin() + m + 1);
    vector<string> right(a.begin() + m + 1, a.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i].size() < right[j].size() || 
           (left[i].size() == right[j].size() && left[i] < right[j])) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}

void mergeSort(vector<string> &a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n;
    cin >> n;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    mergeSort(s, 1, n);

    vector<vector<string>> adj(n + 1);

    int i = 1;
    while (i <= n) {
        int j = i;
        while (j <= n && s[i] == s[j])
            j++;

        adj[j - i].push_back(s[i]);
        i = j;
    }

    for (int i = n; i >= 0; i--) {
        if (adj[i].empty()) continue;
        for (auto res : adj[i]) {
            cout << res << ' ' << i << '\n';
        }
    }
}
