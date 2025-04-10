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
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        
        vector<int> merged;
        merged.reserve(n + m);
        
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) merged.push_back(a[i++]);
            else merged.push_back(b[j++]);
        }
        while (i < n) merged.push_back(a[i++]);
        while (j < m) merged.push_back(b[j++]);
        
        for (int num : merged) cout << num << " ";
        cout << "\n";
    }
    
    return 0;
}
