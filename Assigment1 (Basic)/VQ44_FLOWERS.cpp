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
        freopen("TASK.OUT", "w", stdout);
    }

    int n, k;
    cin >> n >> k;
    map<int, int> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    for (auto it : m) {
        cout << it.first << " ";
        k--;
        if (k == 0) break;
        m[it.first]--;
    }

    if (k > 0) {
        for (auto it : m) {
            for (int i = 0; i < it.second; i++) {
                cout << it.first << " ";
                k--;
                if (k == 0) break;
            }
            if (k == 0) break;
        }
    }

    return 0;
}
