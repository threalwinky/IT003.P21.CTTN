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
    
    map<int, int> m, m2;
    bool flag = 0;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x] = i;
        m2[x] = 1;
    }
    int k;
    cin >> k;
    if (!m2[k]){
        cout << -1;
    }
    else{
        cout << m[k] << "\n" << m[k] + 1 << "\n";
        cout << n - 1 - m[k] << "\n" << n - m[k];
    }
}
