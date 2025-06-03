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
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmp2(A a, A b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x > b.x;
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

void merge2(vector<A> &v, int l, int m, int r) {
    vector<A> left(v.begin() + l, v.begin() + m + 1);
    vector<A> right(v.begin() + m + 1, v.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (cmp2(left[i], right[j])) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
        }
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

void mergeSort2(vector<A> &v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort2(v, l, m);
        mergeSort2(v, m + 1, r);
        merge2(v, l, m, r);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int n, q;
    cin >> n >> q;
    vector<A> v;
    vector<A> v2;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back({x, i});
        v2.push_back({x, i});
    }
    mergeSort(v, 0, n - 1);
    mergeSort2(v2, 0, n - 1);

    while (q--){
        string s;
        cin >> s;
        int type;
        cin >> type;
        int x;
        cin >> x;
        if (type == 1){
            auto it = lower_bound(v.begin(), v.end(), A{x, 0}, cmp);
            if (it->x != x){
                cout << "-1\n";
            }
            else{
                cout << it->y << "\n";
            }
        }
        else {
            auto it = lower_bound(v2.begin(), v2.end(), A{x, 9999999}, cmp2);
            if (it->x != x){
                cout << "-1\n";
            }
            else{
                cout << it->y << "\n";
            }
        }
    }

}
