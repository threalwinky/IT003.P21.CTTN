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
    
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        map<int, int> m;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            m[x]++;
        }
        int s = 0;
        for (auto it : m){
            s += min(it.se, 2LL);
        }
        if (m.size() > 2 * k){
            cout << "NO\n";
            continue;
        }
        if (s >= 2 * k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
