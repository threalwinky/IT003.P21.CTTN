#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n, k, p, q;
    cin >> n >> k >> p >> q;
    
    int alice=q+(p-1)*2;
    
    if (alice-k > 0){
        if ((alice-k)%2 == 0)
            cout << (alice-k+1)/2 << " " << 2;
        else 
            cout << (alice-k+1)/2 << " " << 1;
    }
    else if (alice+k <= n){
        if ((alice+k)%2 == 0)
            cout << (alice+k+1)/2 << " " << 2;
        else
            cout << (alice+k+1)/2 << " " << 1;
    }
    else cout << -1;
}