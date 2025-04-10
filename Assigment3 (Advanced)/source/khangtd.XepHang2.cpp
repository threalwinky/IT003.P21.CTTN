#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int n, q;
    cin >> n >> q;

    list<int> l;
    map<int, list<int>::iterator> pos;

    for (int i = 1; i <= n; ++i) {
        l.push_back(i);
    }

    auto it = l.begin();
    for (int i = 1; i <= n; ++i, ++it) {
        pos[i] = it;
    }

    while (q--) {
        int x;
        cin >> x;
        l.erase(pos[x]);
        l.push_front(x);
        pos[x] = l.begin();
        cout << l.back() << " ";
    }
}
