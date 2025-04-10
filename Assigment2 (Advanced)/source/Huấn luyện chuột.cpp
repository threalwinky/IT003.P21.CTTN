#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

int f[N], inv[N];

int supow(int a, int b, int m){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % m;
        a = a*a % m;
        b >>= 1;
    }
    return res;
}

int C(int k, int n, int p){
    if (k > n) return 0;
    return f[n] * inv[k] % p * inv[n-k] % p;
}

void precompute(int p){
    f[0] = f[1] = 1;
    for(int i = 2; i < p; i++){
        f[i] = f[i-1] * i % p;
    }
    inv[p-1] = supow(f[p-1], p - 2, p);
    for(int i = p - 2; i >= 0; i--){
        inv[i] = inv[i+1] * (i + 1) % p;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int T, n, ans, p; cin >> T >> p;
    precompute(p);
    while(T--){
        cin >> n;
        int ans = 1, cur = p;
        int m = 2*n - 1;
        for(int i = 0; i <= 1e5; i++){
            if (m*p < cur) break;;
            int tmp1 = (n % cur) * p / cur;
            int tmp2 = (m % cur) * p / cur;
            ans = ans * C(tmp1, tmp2, p) % p;
            cur = cur * p;
        }
        cout << ans << "\n";
    }
}
