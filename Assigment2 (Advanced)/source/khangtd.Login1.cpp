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
    
    int n, k;
    cin >> n >> k;
    map<string, string> m;
    for (int i=1; i <= n; i++){
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }
    for (int i=1; i <= k; i++){
        string a;
        cin >> a;
        if (m[a] == ""){
            cout << "Chua Dang Ky!\n";
        }
        else cout << m[a] << "\n";
    }
}
