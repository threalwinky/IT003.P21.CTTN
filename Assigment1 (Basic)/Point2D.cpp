#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

bool cmp(pair<int, int> x, pair<int, int> y){
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    vector<pair<int, int>> v;

    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v){
        cout << it.first << " " << it.second << "\n";
    }
}
