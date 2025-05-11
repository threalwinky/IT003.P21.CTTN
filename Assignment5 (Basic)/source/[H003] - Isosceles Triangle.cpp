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

    int n;
    cin >> n;

    map<int, int> m; 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    vector<pair<int, int>> v;

    for (auto it : m) {
        if (it.fi > 0) { 
            v.push_back({it.fi, it.se});
        }
    }
    
    int M = v.size();
    vector<int> p(M + 1, 0);
    for (int i = 0; i < M; i++) {
        p[i + 1] = p[i] + v[i].se;
    }

    int ans = 0; 
    for (int i = 0; i < M; i++) {
        int x = v[i].fi;  
        int fx = v[i].se; 
        if (fx >= 3) {
            ans += fx * (fx - 1) * (fx - 2) / 6; 
        }

        if (fx >= 2) {
            int a = fx * (fx - 1) / 2;
            auto b = lower_bound(v.begin(), v.end(), make_pair(2 * x, -inf)); 
            
            int c = distance(v.begin(), b);
            int d = p[c], e = d - fx;
            if (e < 0) {
                e = 0; 
            }
            ans += a * e;
        }
    }

    cout << ans;
}

