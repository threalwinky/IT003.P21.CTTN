#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

int solve(vector<int> a) {
    vector<pair<int, int>> b;
    for (int i = 0; i < a.size(); i++) {
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    vector<bool> visited(a.size(), 0);
    int s = 0;
    for (int i = 0; i < a.size(); i++) {
        if (visited[i] || b[i].second == i) continue;
        int c = 0, j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = b[j].second;
            c++;
        }
        if (c > 1) {
            s += c - 1;
        }
    }
    return s;
}

vector<int> rev(vector<int> a){
    vector<int> tmp;
    for(auto it:a){
        tmp.push_back(2e9-it);
    }
    return tmp;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> vr = rev(v);
    cout << min(solve(v), solve(vr));
}
