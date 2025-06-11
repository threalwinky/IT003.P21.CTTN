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
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int c = 1;
        while (!st.empty() && st.top().fi <= v[i]) {
            if (st.top().fi < v[i]) {
                ans += st.top().se;
                st.pop();
            } else { 
                ans += st.top().se;
                c += st.top().se;
                st.pop();
            }
        }
        if (!st.empty()) {
            ans += 1;
        }
        st.push(make_pair(v[i], c));
    }
    cout << ans;
    
}