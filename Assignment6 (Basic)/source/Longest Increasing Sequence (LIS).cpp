#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.fi < b.fi;
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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<pair<int, int>> f;
    vector<int> m(n, -1);

    for (int i = n - 1; i >= 0; --i) {
        int ve = -v[i];
        auto it = lower_bound(f.begin(), f.end(), make_pair(ve, 0LL), cmp);
        int j = distance(f.begin(), it);
        if (j == f.size()) {
            f.emplace_back(ve, i);
        } else {
            f[j] = {ve, i};
        }
        if (j > 0) m[i] = f[j - 1].se;
    }

    vector<int> ans;
    int cur = f.back().se;
    while (cur != -1) {
        ans.push_back(v[cur]);
        cur = m[cur];
    }
    cout << ans.size() << '\n';
    for (auto it : ans){
        cout << it << " ";
    }
    cout << '\n';
}
