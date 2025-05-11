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
    vector<int> v;
    vector<int> p(n + 1);
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> v2;
    v2.push_back(0);
    for (int i=0; i<n; i++){
        v2.push_back(v[i]);  
    }
    for (int i=1; i<=n; i++){
        p[i] = p[i-1] + v2[i];
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        int tmp1 = p[i-1] - p[0];
        int tmp2 = p[n] - p[i];
        ans += (i - 1) * v2[i] - tmp1;
        ans += tmp2 - (n - i) * v2[i];
    }
    cout << ans / 2;
    
}